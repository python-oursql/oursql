import collections, itertools

cdef class Cursor:
    """Cursor(...)
    
    Cursors should never be instantiated directly. They may be passed other 
    options via the Connection.cursor method:
    
      - try_plain_query=True: If this is true, oursql will first attempt to run
        queries as prepared statements, and then fall back to the plain query 
        API if MySQL refuses to parameterize the query. Otherwise, oursql will 
        only run plain queries if explicitly asked.
    
      - show_table=False: If this is true, the name of the table will be 
        prepended to the name of the column in the 'description' attribute of
        the cursor.
    
      - string_limit=0: Set a limit on the size of the buffer oursql will 
        allocate when fetching strings over the wire. If the string_limit is 
        nonzero, file-like objects will always be returned instead of strings. 
        If the size of the string value is greater than the string_limit, the 
        string will be streamed as necessary instead of fetched all at once.
        Note: plain queries buffer incoming result differently, and are 
        therefore unaffected by the string_limit.
    
    Cursor instances yield tuples to represent rows.
    """
    
    cdef readonly object _statements, _stmt_kwargs
    cdef Connection conn
    cdef int closed, try_plain_query
    cdef readonly object rowcount, lastrowid, description, messages
    cdef public unsigned long arraysize
    
    _statement_class = _Statement
    _query_class = _Query
    
    def __cinit__(self, Connection conn not None, bint try_plain_query=True, 
            **kwargs):
        self.conn = conn
        self._stmt_kwargs = kwargs
        self._statements = collections.deque()
        self.messages = []
        self.closed = False
        self.rowcount = -1
        self.arraysize = 1
        self.try_plain_query = try_plain_query
    
    cdef int _check_closed(self) except -1:
        if not self.conn.conn:
            raise ProgrammingError('connection closed')
        if self.closed:
            raise ProgrammingError('cursor closed')
    
    def close(self):
        """close()
        
        Close the cursor and discard the rest of the results. The cursor will
        immediately become unusable.
        """
        self.closed = True
        self._statements.clear()
    
    def _new_statement(self):
        stmt = self._statement_class(self.conn, **self._stmt_kwargs)
        stmt.prefetch_rows = self.arraysize
        return stmt
    
    def _new_query(self, query):
        return self._query_class(self.conn, query, **self._stmt_kwargs)
    
    def callproc(self, procname, params=()):
        """callproc(procname, params=())
        
        Supposedly, run a stored procedure. MySQL's C API has no direct call
        for this; you need to execute stored procedures with the CALL statement
        instead. Calling this method always raises an exception.
        """
        # This is slightly irritating, but not too horribly bad. The horribly 
        # bad part is getting the results from a procedure.
        raise NotSupportedError('use the CALL statement with the execute '
            'method to call stored procedures')
    
    def _do_autoping(self):
        if self.conn.autoping:
            self.conn.ping()
    
    def execute(self, query, params=(), plain_query=False):
        """execute(query, params=(), plain_query=False)
        
        Execute a query. If plain_query is true, run a plain, unparameterized
        query. MySQL cannot parameterize all kinds of statements, which makes
        it sometimes necessary to execute a plain query. If plain_query is true
        and params is true, an exception will be raised as plain queries cannot
        be parameterized.
        """
        self._check_closed()
        self._do_autoping()
        # This, on the other hand, is just plain stupid.
        if plain_query:
            if params:
                # I *really* don't want to write an escaping API. Anything 
                # worth parameterizing supports the prepared statement API
                # anyway, so this shouldn't matter too much.
                raise ProgrammingError("can't call execute with both "
                    "parameters and a plain query")
            stmt = self._new_query(query)
        else:
            stmt = self._new_statement()
            try:
                stmt.prepare(query)
            except Error, e:
                # So, if MySQL refuses to parameterize the query, we optionally
                # try it again through the stupid query API. This is optional
                # because you can lose state data if this is always done 
                # implicitly.
                if self.try_plain_query and e.errno == ER_UNSUPPORTED_PS:
                    return self.execute(query, params, plain_query=True)
                else:
                    raise
            else:
                stmt.execute(*params)
        self._update_fields(stmt)
    
    def executemany(self, query, parambatch):
        """executemany(query, parambatch)
        
        Execute the same query with different sets of parameters. This is more
        efficient than calling execute many times with the same query.
        """
        self._check_closed()
        self._do_autoping()
        # No plain queries because they can't be parameterized anyway.
        stmt = self._new_statement()
        stmt.prepare(query)
        rowcount = 0
        for params in parambatch:
            stmt.execute(*params)
            # There's probably a better way to do this, but whatever. As far as
            # I know we should get all values -1 or all values >= 0.
            rowcount += stmt.rowcount
        # Whatevs.
        if rowcount < 0:
            rowcount = -1
        self._update_fields(stmt, rowcount)
    
    cdef int _update_fields(self, stmt, rowcount=None) except -1:
        self.messages.extend(stmt.warnings)
        if rowcount is None:
            self.rowcount = stmt.rowcount
        else:
            self.rowcount = rowcount
        self.lastrowid = stmt.lastrowid
        self.description = stmt.description
        if stmt.has_result:
            self._statements.append(stmt)
    
    cdef int _check_statements(self) except -1:
        self._check_closed()
        if not self._statements:
            raise ProgrammingError('no results available')
    
    def nextset(self):
        """nextset() -> True or None.
        
        Move to the next result set. If there are any result sets left, this
        returns True. Otherwise, None.
        """
        self._check_statements()
        if self._statements[0].nextset():
            return True
        self._statements.popleft()
        # DB-API, you so wacky.
        return True if self._statements else None
    
    def fetchone(self):
        """fetchone() -> row.
        
        Fetch one row from the current result set. If the result set was
        exhausted, this returns None. If there were no result sets, a 
        ProgrammingError is raised.
        """
        self._check_statements()
        self._do_autoping()
        ret = self._statements[0].fetchone()
        if ret is None:
            self.nextset()
        return ret
    
    def fetchmany(self, size=None):
        """fetchmany(size=self.arraysize) -> list of rows.
        
        Fetch up to 'size' rows. If there aren't that many rows available in 
        the database, this returns as many as were available. If there were no 
        result sets, a ProgrammingError is raised.
        """
        cdef unsigned int i
        self._check_statements()
        self._do_autoping()
        if size is None:
            size = self.arraysize
        ret = []
        resultset = self._statements[0]
        # This is a little bit wacky for DB-API compliance. If there's fewer 
        # rows available than requested, return everything available without
        # switching to the next result set. If there wasn't anything in the
        # result set at all, *then* switch to the next result set and return an
        # empty sequence.
        for 0 <= i < size:
            row = resultset.fetchone()
            if row is None:
                if i == 0:
                    self.nextset()
                return ret
            ret.append(row)
        return ret
    
    def fetchall(self):
        """fetchall() -> list of rows.
        
        Fetch all available rows from the database. If there were no result 
        sets, a ProgrammingError is raised.
        """
        self._check_statements()
        self._do_autoping()
        ret = []
        while self._statements:
            ret.extend(self._statements.popleft().fetchall())
        return ret
    
    def __iter__(self):
        self._check_closed()
        return PyCallIter_New(self.fetchone, None)
    
    property connection:
        def __get__(self):
            return self.conn
    
    def setinputsizes(self, sizes):
        """setinputsizes(sizes)
        
        Do nothing; this operation is not supported by oursql.
        """
        # While I could implement these functions to do something, I don't see
        # it as being very useful for MySQL's C API.
        pass
    
    def setoutputsize(self, size, column=None):
        """setoutputsize(size, column=None)
        
        Do nothing; this operation is not supported by oursql.
        """
        pass
    
    def __enter__(self):
        return self
    
    def __exit__(self, exc, value, tb):
        if exc:
            self.conn.rollback()
        else:
            self.conn.commit()
        self.close()

cdef class DictCursor(Cursor):
    """DictCursor(...)
    
    Cursors should never be instantiated directly. They may be passed other 
    options via the Connection.cursor method. See the documentation for the
    Cursor class for details.
    
    DictCursor instances represent rows as dicts mapping column names or 
    aliases to values. These key names are taken from the 'description' 
    attribute of the cursor, and are therefore affected by the 'show_table'
    cursor option. A ProgrammingError is raised when fetching a row if there 
    were duplicate keys with inequal values.
    """
    
    _statement_class = _DictStatement
    _query_class = _DictQuery
