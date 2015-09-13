# This is definitely my least favorite module in the whole project. I hate you,
# MySQL, I really do. 

cdef class _ResultSet:
    """_ResultSet(...)
    
    You should never ever instantiate a _ResultSet yourself unless you really
    know what you're doing. 
    """
    
    cdef Connection conn
    cdef MYSQL_RES *res
    cdef unsigned int fields
    cdef object conversion_info
    cdef readonly object rowcount, lastrowid, description, column_names
    cdef public object warnings
    cdef int show_table
    
    conversions_dict = _conversions
    
    def __cinit__(self, Connection conn not None, bint show_table=False,
            **kwargs):
        cdef my_ulonglong res
        conn._check_closed()
        self.conn = conn
        self.fields = mysql_field_count(self.conn.conn)
        self.res = mysql_store_result(self.conn.conn)
        if not self.res and self.fields != 0:
            self._raise_error()
        
        res = mysql_affected_rows(self.conn.conn)
        if res == ull_negone:
            self.rowcount = -1
        else:
            self.rowcount = res
        res = mysql_insert_id(self.conn.conn)
        if res == 0:
            self.lastrowid = None
        else:
            self.lastrowid = res
        
        if self.fields:
            self.description = description_from_res(
                conn, self.res, self.fields, self.show_table)
            self.conversion_info = conversion_info_from_res(
                self.res, self.fields)
            self.column_names = [d[0] for d in self.description]
        else:
            self.description = self.column_names = None
        
        if self.conn.warning_count():
            self.warnings = _do_warnings_query(self.conn)
        else:
            self.warnings = []
    
    def __dealloc__(self):
        self.close()
    
    def close(self):
        if self.res:
            mysql_free_result(self.res)
            self.res = NULL
    
    cdef int _raise_error(self) except -1:
        return self.conn._raise_error()
    
    cdef int _check_closed(self) except -1:
        if not self.conn.conn:
            if self.res:
                self.close()
            raise ProgrammingError('connection closed')
        if not self.res:
            raise ProgrammingError('query closed')
    
    property has_result:
        def __get__(self):
            return self.fields != 0
    
    def fetchone(self):
        cdef MYSQL_ROW row
        cdef unsigned int i
        cdef unsigned long *lengths
        self._check_closed()
        row = mysql_fetch_row(self.res)
        if not row:
            return None
        lengths = mysql_fetch_lengths(self.res)
        if not lengths:
            self._raise_error()
        ret = PyTuple_New(self.fields)
        # Cache the connection charset.
        self.conn.charset
        for 0 <= i < self.fields:
            if not row[i]:
                d = None
            else:
                d = PyBytes_FromStringAndSize(row[i], lengths[i])
                field_type, flags, charsetnr = self.conversion_info[i]
                converter = self.conversions_dict.get(field_type)
                if converter:
                    d = converter(d)
                elif self.conn.use_unicode and charsetnr != CS_BINARY:
                    d = d.decode(self.conn._charset)
            Py_INCREF(d)
            PyTuple_SET_ITEM(ret, i, d)
        return ret
    
    def fetchall(self):
        self._check_closed()
        return PySequence_List(self)
    
    def __iter__(self):
        self._check_closed()
        return PyCallIter_New(self.fetchone, None)

cdef class _Query:
    """_Query(...)
    
    _Queries generate _ResultSets. Eventually they will also support generating
    multiple _ResultSets when dealing with queries that produce multiple result
    sets.
    """
    
    cdef Connection conn
    cdef object result, res_a, res_kw
    cdef readonly object rowcount, lastrowid, description, warnings, has_result
    
    def __cinit__(self, Connection conn not None, query, *a, **kw):
        cdef char *qstr
        cdef Py_ssize_t qlen
        conn._check_closed()
        self.conn = conn
        query = bytes_maybe_from_encoding(query, self.conn.charset, False)
        PyBytes_AsStringAndSize(query, &qstr, &qlen)
        if mysql_real_query(self.conn.conn, qstr, qlen):
            self._raise_error()
        self.res_a, self.res_kw = a, kw
        self.warnings = []
        self.new_result()
        # XXX: support multiple result sets.
        self.has_result = self.result.has_result
    
    _result_class = _ResultSet
    def new_result(self):
        res = self._result_class(self.conn, *self.res_a, **self.res_kw)
        self.warnings.extend(res.warnings)
        self.rowcount = res.rowcount
        self.lastrowid = res.lastrowid
        self.description = res.description
        self.result = res
    
    cdef int _raise_error(self) except -1:
        return self.conn._raise_error()
    
    def nextset(self):
        cdef int res
        # XXX: support multiple result sets.
        self.result = None
        return False
        
        if not self.result:
            return False
        self.result.close()
        res = mysql_next_result(self.conn.conn)
        if res > 0:
            self._raise_error()
        elif res == -1:
            self.result = None
            return False
        elif res == 0:
            self.new_result()
            return True
    
    def fetchone(self):
        while self.result is not None:
            if self.result.has_result:
                row = self.result.fetchone()
                if row is not None:
                    return row
            self.nextset()
        return None
    
    def __iter__(self):
        return PyCallIter_New(self.fetchone, None)
    
    def fetchall(self):
        return PySequence_List(self)

# Cython should support multiple inheritance one of these days.
_DictResultSet = type('_DictResultSet', (_DictWhateverMixin, _ResultSet), 
    {'__module__': __name__})

cdef class _DictQuery(_Query):
    _result_class = _DictResultSet
