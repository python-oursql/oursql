import datetime
import decimal
import codecs
import io

cdef my_ulonglong ull_negone = <my_ulonglong>-1

cdef class _AbstractIterWrapper: 
    def __iter__(self):
        return self

cdef class _BinaryWhateverMixin:
    def __next__(self):
        ret = super(BinaryFileWrapper, self).next()
        return ret

cdef class IterWrapper(_AbstractIterWrapper):
    """IterWrapper(iterobj)
    
    IterWrapper is a wrapper class for arbitrary string-yielding iterable 
    objects so that their contents can be streamed over the wire as a bound 
    parameter for a query. The strings are assumed to be text and not arbitrary
    bytes.
    """
    
    cdef object iterobj, nextfunc
    
    def __cinit__(self, iterobj):
        self.iterobj = iter(iterobj)
        self.nextfunc = self.iterobj.next
    
    def __next__(self):
        return self.nextfunc()

BinaryIterWrapper = type('BinaryIterWrapper', 
    (_BinaryWhateverMixin, IterWrapper), {'__module__': __name__, '__doc__':
    """BinaryIterWrapper(iterobj)
    
    BinaryIterWrapper behaves like IterWrapper, except the strings yielded from
    the iterable are treated as bytes instead of text strings.
    """})

cdef class FileWrapper(_AbstractIterWrapper):
    """FileWrapper(fileobj, chunksize=8192, doclose=False)
    
    FileWrapper is a wrapper class for file-like objects so that their contents
    can be streamed over the wire as a bound parameter for a query. Strings 
    read from the wrapped file are assumed to be text and not arbitrary bytes.
    
    Strings will be read by calling the 'read' method on the file object with
    the 'chunksize' parameter until it returns the empty string. If 'doclose'
    is true, the file will have its 'close' method called once it has been 
    exhausted.
    """
    
    cdef object fileobj, chunksize, readfunc
    cdef int doclose, done
    
    def __cinit__(self, fileobj, chunksize=8192, bint doclose=False):
        self.fileobj = fileobj
        self.readfunc = fileobj.read
        self.chunksize = chunksize
        self.doclose = doclose
        self.done = False
    
    def __next__(self):
        if self.done:
            raise StopIteration
        ret = self.readfunc(self.chunksize)
        if not ret:
            if self.doclose:
                self.fileobj.close()
            self.done = True
            raise StopIteration
        return ret

BinaryFileWrapper = type('BinaryFileWrapper', 
    (_BinaryWhateverMixin, FileWrapper), {'__module__': __name__, '__doc__':
    """BinaryFileWrapper(fileobj, chunksize=8192, doclose=False)
    
    BinaryFileWrapper behaves exactly like FileWrapper, except the strings 
    yielded from the file object are treated as bytes instead of text strings.
    """})

cdef class _Statement:
    """_Statement(...)
    
    A class that represents a prepared statement. You should probably avoid
    touching this, even if it's more stable than _Query/_ResultSet.
    """
    cdef object __weakref__
    cdef MYSQL_STMT *stmt
    cdef MYSQL_BIND *bind
    cdef column_output *result_data
    cdef unsigned int result_fields, fetched
    cdef unsigned long cursor_type, string_limit, _prefetch_rows
    cdef int buffered, data_waiting, show_table, exhausted
    cdef Connection conn
    cdef public object warnings
    
    def __cinit__(self, Connection connection not None, 
            unsigned long string_limit=0, bint show_table=False, **kwargs):
        self.conn = connection
        self.stmt = mysql_stmt_init(self.conn.conn)
        if not self.stmt:
            raise MemoryError('alloc of statement failed')
        self.string_limit = string_limit
        self.show_table = show_table
        self.result_data = NULL
        self.warnings = []
        self.buffered = self.data_waiting = self.exhausted = False
        if _oursqlx_init_stmt_cursor(self.stmt, &self.cursor_type):
            self._raise_error()
    
    def __dealloc__(self):
        self.close()
        PyMem_Free(self.result_data)
        PyMem_Free(self.bind)
    
    def close(self):
        if self.stmt:
            mysql_stmt_close(self.stmt)
            self.stmt = NULL
    
    cdef int _raise_error(self) except -1:
        cdef int err = mysql_stmt_errno(self.stmt)
        # effect a sideeffect by looking up the charset, required for
        # _decode_char_p
        self.conn.charset
        raise _exception_from_errno(err)(
            self.conn._decode_char_p(mysql_stmt_error(self.stmt)), err)
    
    cdef int _check_closed(self) except -1:
        if not self.conn.conn:
            if self.stmt:
                self.close()
            raise ProgrammingError('connection closed')
        if not self.stmt:
            raise ProgrammingError('statement closed')
    
    property string_limit:
        def __get__(self):
            return self.string_limit
        
        def __set__(self, unsigned long value):
            if value < 0:
                raise ValueError('string limit must be >= 0')
            self.string_limit = value
    
    def prepare(self, statement):
        cdef char *buf
        cdef Py_ssize_t bufsize
        self._check_closed()
        if self.data_waiting:
            raise ProgrammingError('binding this query would cause rows to '
                'become unfetchable')
        statement = bytes_maybe_from_encoding(
            statement, self.conn.charset, False)
        PyBytes_AsStringAndSize(statement, &buf, &bufsize)
        if mysql_stmt_prepare(self.stmt, buf, bufsize):
            self._raise_error()
        self._alloc_buffer()
    
    cdef int _alloc_buffer(self) except -1:
        cdef MYSQL_RES *res
        cdef MYSQL_BIND *bind = NULL
        cdef column_output *result_data = NULL
        res = mysql_stmt_result_metadata(self.stmt)
        
        # Okay so. MySQL doesn't require that we keep around the MYSQL_BIND 
        # structure that we pass to mysql_stmt_bind_result, but we do have to
        # keep around the buffers that we've bound to hold the results. If 
        # there's a failure at this point, we're pretty much screwed since the
        # result buffers won't be prepared and we can't restore the old 
        # prepared statement.
        
        # So! Since we have no reason not to, we free any previously bound 
        # buffers.
        PyMem_Free(self.result_data)
        self.result_data = NULL
        # But if we don't need any buffers, we're done anyway.
        if not res:
            return 0
        
        try:
            # Otherwise, we (try to) allocate the result buffers.
            fields = mysql_num_fields(res)
            bind = <MYSQL_BIND *>PyMem_Malloc(sizeof(MYSQL_BIND) * fields)
            if not bind:
                raise MemoryError('alloc of result bind structure failed')
            memset(bind, 0, sizeof(MYSQL_BIND) * fields)
            result_data = <column_output *>PyMem_Malloc(
                sizeof(column_output) * fields)
            if not result_data:
                raise MemoryError('alloc of result buffers failed')
            memset(result_data, 0, sizeof(column_output) * fields)
        except:
            # We only want to free the buffers if there was a failure and we 
            # can't use 'em.
            PyMem_Free(result_data)
            PyMem_Free(bind)
            raise
        else:
            # And we only want to save the buffers if there was no failure.
            self.bind = bind
            self.result_data = result_data
            self.result_fields = fields
        finally:
            # But in any case, we don't need the result.
            mysql_free_result(res)
    
    cdef int _bind_buffer(self) except -1:
        cdef MYSQL_RES *res
        cdef MYSQL_FIELD *field
        cdef MYSQL_BIND *b
        cdef column_output *c
        cdef unsigned int fields, i
        res = mysql_stmt_result_metadata(self.stmt)
        
        try:
            # And now we (try to) set up the result buffers.
            fields = mysql_num_fields(res)
            for 0 <= i < fields:
                b, c = &self.bind[i], &self.result_data[i]
                field = mysql_fetch_field_direct(res, i)
                if field.type == MYSQL_TYPE_GEOMETRY:
                    c.type = b.buffer_type = MYSQL_TYPE_STRING
                else:
                    c.type = b.buffer_type = field.type
                c.flags = field.flags
                c.is_binary = (field.charsetnr == CS_BINARY)
                b.buffer_length = sizeof(column_data)
                b.buffer = &c.buf
                b.length = &c.length
                b.is_null = &c.is_null
                b.error = &c.error
                if field.flags & UNSIGNED_NUM_FLAG == UNSIGNED_NUM_FLAG:
                    b.is_unsigned = True
            if mysql_stmt_bind_result(self.stmt, self.bind):
                self._raise_error()
        finally:
            # And clean up the result data.
            mysql_free_result(res)
    
    property has_result:
        def __get__(self):
            self._check_closed()
            return self.result_data != NULL
    
    property description:
        def __get__(self):
            cdef MYSQL_RES *res
            self._check_closed()
            if not self.result_data:
                return None
            res = mysql_stmt_result_metadata(self.stmt)
            if not res:
                self.result_data = NULL
                return
            try:
                ret = description_from_res(
                    self.conn, res, self.result_fields, self.show_table)
            finally:
                mysql_free_result(res)
            return ret
    
    property column_names:
        def __get__(self):
            desc = self.description
            if desc is None:
                return None
            return [x[0] for x in desc]
    
    def execute(self, *parameters):
        cdef char *buf = NULL
        cdef void *long_buffer
        cdef MYSQL_BIND *bind = NULL, *b
        cdef column_data *column, *c
        cdef Py_ssize_t i, n_params, stmt_params, long_buffer_size
        self._check_closed()
        if self.data_waiting:
            raise ProgrammingError('executing this query would cause rows to '
                'become unfetchable')
        n_params = PyTuple_GET_SIZE(parameters)
        stmt_params = mysql_stmt_param_count(self.stmt)
        if stmt_params != n_params:
            raise ProgrammingError('%d parameters expected, %d given' % (
                stmt_params, n_params))
        long_strings = []
        # So we don't have temporary values cleaned up before they're used.
        temp_strings = []
        try:
            if n_params > 0:
                buf = <char *>PyMem_Malloc(
                    (sizeof(MYSQL_BIND) + sizeof(column_data)) * n_params)
                if not buf:
                    raise MemoryError('alloc of bind parameters failed')
                bind = <MYSQL_BIND *>buf
                memset(bind, 0, sizeof(MYSQL_BIND) * n_params)
                column = <column_data *>(buf + (sizeof(MYSQL_BIND) * n_params))
                memset(column, 0, sizeof(column_data) * n_params)
                # Cache the connection charset.
                self.conn.charset
                for 0 <= i < n_params:
                    o = PyTuple_GET_ITEM(parameters, i)
                    Py_INCREF(o)
                    b, c = &bind[i], &column[i]
                    # This monolith should be refactored into something better
                    # someday. It can't really work the same way as MySQLdb has
                    # a conversion dict, since this involves some C-level union
                    # and buffer munging. 
                    if o is None:
                        b.buffer_type = MYSQL_TYPE_NULL
                        b.buffer = NULL
                    elif PyUnicode_Check(o):
                        b.buffer_type = MYSQL_TYPE_STRING
                        if self.conn.use_unicode:
                            o = o.encode(self.conn._charset)
                            temp_strings.append(o)
                        PyBytes_AsStringAndSize(o, 
                            <char **>&b.buffer, &c.st)
                        c.ul = c.st
                        b.length = &c.ul
                    elif PyBytes_Check(o):
                        b.buffer_type = MYSQL_TYPE_STRING
                        PyBytes_AsStringAndSize(o, 
                            <char **>&b.buffer, &c.st)
                        c.ul = c.st
                        b.length = &c.ul
                    elif PyInt_Check(o):
                        # MYSQL_TYPE_LONG really takes a C int, not a C long.
                        # This is necessary for platforms where sizeof(long) >
                        # sizeof(int).
                        b.buffer_type = MYSQL_TYPE_LONGLONG
                        c.ll = PyInt_AS_LONG(o)
                        b.buffer = <void *>&c.ll
                    elif PyLong_Check(o):
                        b.buffer_type = MYSQL_TYPE_LONGLONG
                        if o >= 0:
                            c.ull = PyLong_AsUnsignedLongLong(o)
                            b.buffer = <void *>&c.ull
                            b.is_unsigned = True
                        else:
                            c.ll = PyLong_AsLongLong(o)
                            b.buffer = <void *>&c.ll
                    elif PyFloat_Check(o):
                        b.buffer_type = MYSQL_TYPE_DOUBLE
                        c.d = PyFloat_AS_DOUBLE(o)
                        b.buffer = <void *>&c.d
                    elif PyDateTime_Check(o):
                        b.buffer_type = MYSQL_TYPE_DATETIME
                        c.t.year = PyDateTime_GET_YEAR(o)
                        c.t.month = PyDateTime_GET_MONTH(o)
                        c.t.day = PyDateTime_GET_DAY(o)
                        c.t.hour = PyDateTime_DATE_GET_HOUR(o)
                        c.t.minute = PyDateTime_DATE_GET_MINUTE(o)
                        c.t.second = PyDateTime_DATE_GET_SECOND(o)
                        c.t.second_part = PyDateTime_DATE_GET_MICROSECOND(o)
                        b.buffer = <void *>&c.t
                    elif PyDate_Check(o):
                        b.buffer_type = MYSQL_TYPE_DATE
                        c.t.year = PyDateTime_GET_YEAR(o)
                        c.t.month = PyDateTime_GET_MONTH(o)
                        c.t.day = PyDateTime_GET_DAY(o)
                        b.buffer = <void *>&c.t
                    elif PyTime_Check(o):
                        b.buffer_type = MYSQL_TYPE_TIME
                        c.t.hour = PyDateTime_TIME_GET_HOUR(o)
                        c.t.minute = PyDateTime_TIME_GET_MINUTE(o)
                        c.t.second = PyDateTime_TIME_GET_SECOND(o)
                        c.t.second_part = PyDateTime_TIME_GET_MICROSECOND(o)
                        b.buffer = <void *>&c.t
                    elif isinstance(o, decimal.Decimal):
                        b.buffer_type = MYSQL_TYPE_NEWDECIMAL
                        o = str(o).encode()
                        temp_strings.append(o)
                        b.buffer = PyBytes_AS_STRING(o)
                        c.ul = PyBytes_GET_SIZE(o)
                        b.length = &c.ul
                    elif isinstance(o, _AbstractIterWrapper):
                        b.buffer_type = MYSQL_TYPE_STRING
                        b.length = &c.ul
                        long_strings.append((i, o))
                    else:
                        raise TypeError('cannot bind %r object' % o.__class__)
            if mysql_stmt_bind_param(self.stmt, bind):
                self._raise_error()
            for i, o in long_strings:
                for s in o:
                    if self.conn.use_unicode:
                        s = s.encode(self.conn._charset)
                    PyBytes_AsStringAndSize(s, 
                        <char **>&long_buffer, &long_buffer_size)
                    if mysql_stmt_send_long_data(self.stmt, i, 
                            <char *>long_buffer, long_buffer_size):
                        self._raise_error()
            if mysql_stmt_execute(self.stmt):
                self._raise_error()
            if _oursqlx_stmt_cursor_prefetch(self.stmt, &self.buffered):
                self._raise_error()
            self.exhausted = False
            if self.result_data:
                self.data_waiting = True
            if self.conn.warning_count():
                self.warnings.extend(_do_warnings_query(self.conn))
        finally:
            PyMem_Free(buf)
    
    def fetchone(self):
        cdef MYSQL_BIND b_tryagain
        cdef column_output *c
        cdef column_data *d
        cdef unsigned int i
        cdef int result
        cdef uint64_t u
        self._check_closed()
        if not self.result_data or self.exhausted:
            return None
        elif self.result_data:
            self._bind_buffer()
        result = mysql_stmt_fetch(self.stmt)
        self.fetched += 1
        if result == 1:
            self._raise_error()
        elif result == MYSQL_NO_DATA:
            if mysql_stmt_free_result(self.stmt):
                self._raise_error()
            self.buffered = self.data_waiting = False
            self.exhausted = True
            return None
        if self.result_fields == 0:
            return ()
        ret = PyTuple_New(self.result_fields)
        # Cache the connection charset.
        self.conn.charset
        for 0 <= i < self.result_fields:
            c = &self.result_data[i]
            d = &c.buf
            if c.is_null:
                val = None
            elif c.type in (MYSQL_TYPE_STRING, MYSQL_TYPE_BLOB, 
                    MYSQL_TYPE_VAR_STRING):
                # Oh string handling.
                val = None
                # If the string wasn't too long to fit in our minimal buffer,
                # then we can just copy it out of the buffer.
                if not c.error:
                    val = PyBytes_FromStringAndSize(&d.c, c.length)
                # If we already have all the results stored clientside, or we
                # don't care about strings being too long, or we *do* care 
                # about strings being too long and it's not too long...
                elif (self.buffered
                        or not self.string_limit 
                        or c.length <= self.string_limit):
                    # First, allocate a string of the necessary length.
                    val = PyBytes_FromStringAndSize(NULL, c.length)
                    # Then, fill up a MYSQL_BIND that will fetch into the 
                    # aforementioned string.
                    memset(&b_tryagain, 0, sizeof(MYSQL_BIND))
                    b_tryagain.buffer_type = MYSQL_TYPE_BLOB
                    b_tryagain.buffer_length = c.length
                    b_tryagain.buffer = PyBytes_AS_STRING(val)
                    # This means that if there is still a truncation error for
                    # whatever reason, something later in the function will
                    # complain.
                    b_tryagain.error = &c.error
                    # Aaand fetch it.
                    if mysql_stmt_fetch_column(self.stmt, &b_tryagain, i, 0):
                        self._raise_error()
                # But, if we care about the length of the string, we need to
                # make sure we have a consistent API.
                if self.string_limit:
                    # At this point, if 'val' still isn't set, it means we 
                    # should stream it from the database.
                    if val is None:
                        val = _ResultStringStream(self, i, c.length)
                        c.error = False
                    # Since _ResultStringStream has a file-like interface, we
                    # make sure that everything passed back has a file-like
                    # interface.
                    else:
                        val = io.BytesIO(val)
                    # And if we're decoding unicode, decode unicode in a 
                    # streaming fashion!
                    if self.conn.use_unicode and not c.is_binary:
                        val = codecs.getreader(self.conn._charset)(val)
                else:
                    # At this point, 'val' should be a string read in from the
                    # database since there's no possibility of streaming. If 
                    # we're handling unicode, decode it.
                    if self.conn.use_unicode and not c.is_binary:
                        val = val.decode(self.conn._charset)
            elif c.type in (MYSQL_TYPE_DECIMAL, MYSQL_TYPE_NEWDECIMAL):
                val = decimal.Decimal(
                PyBytes_FromStringAndSize(d.dec, c.length).decode(self.conn._charset))
            # Sometimes mysql likes to give back invalid data instead of doing
            # anything sensible.
            elif c.type in (MYSQL_TYPE_DATETIME, MYSQL_TYPE_TIMESTAMP, 
                    MYSQL_TYPE_DATE) and d.t.year == 0:
                val = None
            elif c.type in (MYSQL_TYPE_DATETIME, MYSQL_TYPE_TIMESTAMP):
                val = PyDateTime_FromDateAndTime(d.t.year, d.t.month, d.t.day, 
                    d.t.hour, d.t.minute, d.t.second, d.t.second_part)
            elif c.type == MYSQL_TYPE_DATE:
                val = PyDate_FromDate(d.t.year, d.t.month, d.t.day)
            elif c.type == MYSQL_TYPE_TIME:
                val = PyTime_FromTime(
                    d.t.hour, d.t.minute, d.t.second, d.t.second_part)
            elif c.type == MYSQL_TYPE_TINY:
                if c.flags & UNSIGNED_FLAG == UNSIGNED_FLAG:
                    val = PyLong_FromUnsignedLong(d.u8)
                else:
                    val = PyLong_FromLong(d.s8)
            elif c.type in (MYSQL_TYPE_SHORT, MYSQL_TYPE_YEAR):
                if c.flags & UNSIGNED_FLAG == UNSIGNED_FLAG:
                    val = PyLong_FromUnsignedLong(d.u16)
                else:
                    val = PyLong_FromLong(d.s16)
            elif c.type in (MYSQL_TYPE_LONG, MYSQL_TYPE_INT24):
                if c.flags & UNSIGNED_FLAG == UNSIGNED_FLAG:
                    val = PyLong_FromUnsignedLong(d.u32)
                else:
                    val = PyLong_FromLong(d.s32)
            elif c.type == MYSQL_TYPE_LONGLONG:
                if c.flags & UNSIGNED_FLAG == UNSIGNED_FLAG:
                    val = PyLong_FromUnsignedLongLong(d.u64)
                else:
                    val = PyLong_FromLongLong(d.s64)
            elif c.type == MYSQL_TYPE_FLOAT:
                val = d.f
            elif c.type == MYSQL_TYPE_DOUBLE:
                val = d.d
            elif c.type == MYSQL_TYPE_BIT:
                # Bitfields column come variable-length and always in big-
                # endian format. Convert it to an int instead of passing back 
                # a string that people would probably be converting to ints 
                # anyway.
                val = bitval_from_char_p(<unsigned char *>&d.c, c.length)
            else:
                val = PyBytes_FromStringAndSize(&d.c, c.length)
                PyErr_WarnEx(Warning, "unknown column returned as string", 1)
            if c.error:
                # This *shouldn't* ever happen.
                raise InterfaceError('truncated column %d, type %d' % (
                    i, c.type))
            Py_INCREF(val)
            PyTuple_SET_ITEM(ret, i, val)
        return ret
    
    def fetchall(self):
        # buffer_results() calls _check_closed()
        self.buffer_results()
        return PySequence_List(self)
    
    def buffer_results(self):
        self._check_closed()
        if not self.buffered:
            if mysql_stmt_store_result(self.stmt):
                self._raise_error()
            self.buffered = True
    
    def nextset(self):
        return False
    
    def __iter__(self):
        self._check_closed()
        return PyCallIter_New(self.fetchone, None)
    
    property rowcount:
        def __get__(self):
            cdef my_ulonglong res
            self._check_closed()
            res = mysql_stmt_affected_rows(self.stmt)
            if res == ull_negone:
                return -1
            else:
                return res
    
    property lastrowid:
        def __get__(self):
            cdef my_ulonglong res
            self._check_closed()
            res = mysql_stmt_insert_id(self.stmt)
            if res == 0:
                return None
            else:
                return res
    
    property prefetch_rows:
        def __get__(self):
            return self._prefetch_rows
        
        def __set__(self, unsigned long value):
            if value < 1:
                raise ValueError('must prefetch at least 1 row')
            self._prefetch_rows = value
            if _oursqlx_stmt_set_prefetch_rows(self.stmt, 
                    &self._prefetch_rows):
                self._raise_error()

_DictStatement = type('_DictStatement', (_DictWhateverMixin, _Statement), 
    {'__module__': __name__})

cdef class _ResultStringStream:
    """_ResultStringStream(...)
    
    _ResultStringStream represents an incoming stream of binary data from the
    database. You should never ever instantiate this class yourself.
    
    A _ResultStringStream must be used immediately; fetching any additional 
    rows from the database will cause it to go out of sync and become unusable.
    """
    
    cdef MYSQL_BIND bind
    cdef _Statement stmt
    cdef unsigned int index, stmt_fetched
    cdef unsigned long offset, length
    cdef int done
    
    def __cinit__(self, _Statement stmt not None, unsigned int index, 
            unsigned int length):
        self.stmt = stmt
        self.stmt_fetched = stmt.fetched
        self.index = index
        self.length = length
        self.offset = 0
        memset(&self.bind, 0, sizeof(MYSQL_BIND))
        self.bind.buffer_type = MYSQL_TYPE_BLOB
        self.bind.length = &self.length
        self.done = False
    
    def read(self, Py_ssize_t size=-1):
        """read(size=-1) -> str
        
        Read some bytes from the database. Reading -1 bytes will attempt to 
        fetch all remaining bytes.
        """
        cdef Py_ssize_t left
        if self.done:
            return ''
        self.stmt._check_closed()
        if self.stmt.fetched != self.stmt_fetched:
            raise ProgrammingError('row no longer available from database')
        left = self.length - self.offset
        if size == -1 or size > left:
            size = left
        elif size < 0:
            raise ValueError("can't read negative bytes")
        ret = PyBytes_FromStringAndSize(NULL, size)
        self.bind.buffer_length = size
        self.bind.buffer = PyBytes_AS_STRING(ret)
        if mysql_stmt_fetch_column(self.stmt.stmt, 
                &self.bind, self.index, self.offset):
            self.stmt._raise_error()
        self.offset += size
        left = self.length - self.offset
        assert left >= 0, 'size remaining should be >= 0'
        if left == 0:
            self.done = True
        return ret
