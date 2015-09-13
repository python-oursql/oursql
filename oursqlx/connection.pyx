_protocol_enum_map = {
    None: MYSQL_PROTOCOL_DEFAULT,
    'tcp': MYSQL_PROTOCOL_TCP,
    'socket': MYSQL_PROTOCOL_SOCKET,
    'pipe': MYSQL_PROTOCOL_PIPE,
    'memory': MYSQL_PROTOCOL_MEMORY,
}

cdef class Connection:
    """Connection([host, user, passwd,] db=None, port=0, unix_socket=None, 
        connect_timeout=None, read_timeout=None, write_timeout=None, 
        protocol=None, ssl=None, read_default_file=None, 
        read_default_group=None, init_command=None, charset_dir=None, 
        shared_memory_base_name=None, local_infile=False, 
        require_secure_auth=False, report_truncation=True, compress=False, 
        found_rows=True, use_unicode=True, charset='utf8', autoping=False, 
        default_cursor=None, raise_on_warnings=True, autoreconnect=False)
    
    Connect to the MySQL database. The first three parameters may be passed by 
    position, but the rest may only be passed by keyword. All options except 
    'use_unicode', 'charset', 'autoping', 'default_cursor', and 
    'raise_on_warnings' correspond with parameters or flags to the 
    mysql_real_connect function, or options to the mysql_options function. 
    
    'protocol' can be one of None, 'tcp', 'socket', 'pipe', or 'memory'. A
    'protocol' of None will use the default protocol, and values otherwise 
    correspond with the potential values of the 'protocol' option in the option 
    file.
    
    'ssl' can either be None or a dict where each key corresponds to a 
    parameter of the mysql_ssl_set function, e.g. {'capath': '/etc/ssl/ca', 
    'cipher': 'DHE-RSA-AES256-SHA'}. Unspecified keys are the same as passing
    NULL to that parameter.
    
    If 'use_unicode' is true, oursql will attempt to return unicode wherever 
    feasible. If 'charset' is not None, oursql will set the connection charset 
    to the value provided. 'charset' defaults to using utf-8. If 'autoping' is 
    true, oursql will run the 'ping' method before executing queries or 
    fetching results to attempt to prevent connection timeout errors. 
    'default_cursor', if provided, will be used as the default cursor class 
    when calling the 'cursor' method. If 'raise_on_warnings' is true, oursql
    will raise a CollatedWarningsError exception if there were any warnings
    produced by running a query.
    
    Connections and their cursors can also be used as context managers.
    
        with some_connection.cursor() as cursor:
            do_something_with(cursor)
    
    Can also be written as:
    
        with some_connection as cursor:
            do_something_with(cursor)
    
    And both are equivalent to:
    
        cursor = some_connection.cursor()
        try:
            do_something_with(cursor)
        except:
            some_connection.rollback()
            raise
        else:
            some_connection.commit()
        finally:
            cursor.close()
    
    """
    
    cdef object __weakref__
    cdef MYSQL *conn
    cdef object _charset, _charset_bytes, _context_cursors
    cdef readonly int use_unicode, autoping, raise_on_warnings
    cdef public object default_cursor
    
    def __cinit__(self, host=None, user=None, passwd=None, *, db=None, 
            unsigned int port=0, unix_socket=None, connect_timeout=None, 
            read_timeout=None, write_timeout=None, protocol=None, ssl=None, 
            read_default_file=None, read_default_group=None, init_command=None, 
            charset_dir=None, shared_memory_base_name=None, 
            bint local_infile=False, bint require_secure_auth=False, 
            bint compress=False, bint report_truncation=True, 
            bint found_rows=True, bint use_unicode=True, charset='utf8', 
            bint autoping=False, default_cursor=None, 
            bint raise_on_warnings=True, bint multi_results=True, 
            bint multi_statements=True, bint autoreconnect=False):
        cdef unsigned long flags = 0
        cdef unsigned int uint_tmp
        cdef my_bool bool_tmp
        if compress:
            flags |= CLIENT_COMPRESS
        if found_rows:
            flags |= CLIENT_FOUND_ROWS
        # I'll come back to this later. Dealing with multiple result sets is
        # such a pain.
        #if multi_results:
        #    flags |= CLIENT_MULTI_RESULTS
        #if multi_statements:
        #    flags |= CLIENT_MULTI_STATEMENTS
        self.conn = mysql_init(NULL)
        if not self.conn:
            raise MemoryError('alloc of conn object failed')
        if protocol not in _protocol_enum_map:
            raise ProgrammingError('unknown protocol %r' % (protocol,))
        host = bytes_maybe_from_encoding(host, charset)
        user = bytes_maybe_from_encoding(user, charset)
        passwd = bytes_maybe_from_encoding(passwd, charset)
        db = bytes_maybe_from_encoding(db, charset)
        unix_socket = bytes_maybe_from_encoding(unix_socket, charset)
        uint_tmp = _protocol_enum_map[protocol]
        mysql_options(self.conn, MYSQL_OPT_PROTOCOL, <char *>&uint_tmp)
        bool_tmp = report_truncation
        mysql_options(self.conn, 
            MYSQL_REPORT_DATA_TRUNCATION, <char *>&bool_tmp)
        bool_tmp = require_secure_auth
        mysql_options(self.conn, MYSQL_SECURE_AUTH, <char *>&bool_tmp)
        if connect_timeout is not None:
            uint_tmp = connect_timeout
            mysql_options(self.conn, 
                MYSQL_OPT_CONNECT_TIMEOUT, <char *>&uint_tmp)
        if read_timeout is not None:
            uint_tmp = read_timeout
            mysql_options(self.conn, 
                MYSQL_OPT_READ_TIMEOUT, <char *>&uint_tmp)
        if write_timeout is not None:
            uint_tmp = write_timeout
            mysql_options(self.conn, 
                MYSQL_OPT_WRITE_TIMEOUT, <char *>&uint_tmp)
        if read_default_file:
            read_default_file = bytes_maybe_from_encoding(
                read_default_file, charset)
            mysql_options(self.conn, 
                MYSQL_READ_DEFAULT_FILE, bytes_or_null(read_default_file))
        if read_default_group:
            read_default_group = bytes_maybe_from_encoding(
                read_default_group, charset)
            mysql_options(self.conn, 
                MYSQL_READ_DEFAULT_GROUP, bytes_or_null(read_default_group))
        if init_command:
            init_command = bytes_maybe_from_encoding(init_command, charset)
            mysql_options(self.conn, 
                MYSQL_INIT_COMMAND, bytes_or_null(init_command))
        if charset_dir:
            charset_dir = bytes_maybe_from_encoding(charset_dir, charset)
            mysql_options(self.conn, 
                MYSQL_INIT_COMMAND, bytes_or_null(charset_dir))
        if shared_memory_base_name:
            shared_memory_base_name = bytes_maybe_from_encoding(
                shared_memory_base_name, charset)
            mysql_options(self.conn, 
                MYSQL_INIT_COMMAND, bytes_or_null(shared_memory_base_name))
        if local_infile:
            mysql_options(self.conn, MYSQL_OPT_LOCAL_INFILE, NULL)
        if ssl is not None:
            self._setup_ssl_options(charset, **ssl)
        if charset is not None:
            charset = PyUnicode_AsUTF8String(charset)
            mysql_options(self.conn, 
                MYSQL_SET_CHARSET_NAME, PyBytes_AS_STRING(charset))
        if not mysql_real_connect(self.conn, bytes_or_null(host), 
                bytes_or_null(user), bytes_or_null(passwd), bytes_or_null(db), 
                port, bytes_or_null(unix_socket), flags):
            self._raise_error()
        if autoreconnect:
            bool_tmp = True
            mysql_options(self.conn, MYSQL_OPT_RECONNECT, <char *>&bool_tmp)
        self.charset
        self.use_unicode = use_unicode
        self.autoping = autoping
        if default_cursor is None:
            default_cursor = Cursor
        self.default_cursor = default_cursor
        self.raise_on_warnings = raise_on_warnings
        self._context_cursors = []
    
    def _setup_ssl_options(self, charset, *, key=None, cert=None, ca=None, 
            capath=None, cipher=None):
        key = bytes_maybe_from_encoding(key, charset)
        cert = bytes_maybe_from_encoding(cert, charset)
        ca = bytes_maybe_from_encoding(ca, charset)
        capath = bytes_maybe_from_encoding(capath, charset)
        cipher = bytes_maybe_from_encoding(cipher, charset)
        mysql_ssl_set(self.conn, bytes_or_null(key), bytes_or_null(cert), 
            bytes_or_null(ca), bytes_or_null(capath), bytes_or_null(cipher))
    
    def close(self):
        """close()
        
        Close the connection. The connection object and all associated cursors
        will become unusable.
        """
        if self.conn:
            self.rollback()
            mysql_close(self.conn)
            self.conn = NULL
    
    def __dealloc__(self):
        if self.conn:
            mysql_close(self.conn)
            self.conn = NULL
    
    cdef int _raise_error(self) except -1:
        # _raise_error can only be called internally, so we shouldn't need to
        # check for if the connection is closed.
        cdef int err = mysql_errno(self.conn)
        self.charset
        raise _exception_from_errno(err)(
            self._decode_char_p(mysql_error(self.conn)), err)
    
    cdef int _check_closed(self) except -1:
        if not self.conn:
            raise ProgrammingError('connection closed')
    
    def ping(self):
        """ping()
        
        Make sure that the database connection is still open. If not, silently
        reconnect.
        """
        self._check_closed()
        if mysql_ping(self.conn):
            self._raise_error()
    
    def commit(self):
        """commit()
        
        Commit the current transaction.
        """
        self._check_closed()
        if mysql_commit(self.conn):
            self._raise_error()
    
    def rollback(self):
        """rollback()
        
        Roll back the current transaction.
        """
        self._check_closed()
        if mysql_rollback(self.conn):
            self._raise_error()
    
    property charset:
        """charset -> str
        
        Get or set the connection's current encoding. If use_unicode is 
        enabled, this is the encoding that will be used to decode incoming
        strings.
        """
        def __get__(self):
            self._charset_bytes = PyBytes_FromString(
                mysql_character_set_name(self.conn))
            self._charset = PyUnicode_FromStringAndSize(
                PyBytes_AS_STRING(self._charset_bytes),
                PyBytes_GET_SIZE(self._charset_bytes))
            return self._charset
        def __set__(self, value):
            self._check_closed()
            svalue = PyUnicode_AsUTF8String(value)
            if mysql_set_character_set(self.conn, PyBytes_AS_STRING(svalue)):
                self._raise_error()
            self._charset_bytes = svalue
            self._charset = value
    
    cdef object _decode_char_p(self, const_char *value):
        cdef Py_ssize_t length = strlen(value)
        return PyUnicode_Decode(value, length, 
            PyBytes_AS_STRING(self._charset_bytes), "strict")
    
    def warning_count(self):
        """warning_count() -> int
        
        Return the number of warnings caused by the most-previously-executed
        query or statement.
        """
        return mysql_warning_count(self.conn)
    
    def cursor(self, cursor_class=None, **kwargs):
        """cursor([cursor_class,] **cursor_options) -> Cursor.
        
        Create a new cursor associated with this connection of the specified 
        type. If no cursor class is specified, the 'default_cursor' attribute
        is used as the cursor class. The cursor_options will be forwarded to 
        the cursor's initializer; see the documentation for the cursor classes 
        for details.
        """
        self._check_closed()
        if cursor_class is None:
            cursor_class = self.default_cursor
        return cursor_class(self, **kwargs)
    
    property server_info:
        def __get__(self):
            cdef const_char *info
            self._check_closed()
            self.charset
            return self._decode_char_p(mysql_get_server_info(self.conn))
    
    property ssl_cipher:
        def __get__(self):
            cdef const_char *res
            self._check_closed()
            res = mysql_get_ssl_cipher(self.conn)
            if not res:
                return None
            self.charset
            return self._decode_char_p(res)
    
    # Unless someone is monkeying around with calling __enter__ and __exit__
    # manually, this approach is the simplest. Yaaay mostly-reentrant code.
    def __enter__(self):
        curs = self.cursor()
        self._context_cursors.append(curs)
        return curs.__enter__()
    
    def __exit__(self, exc, value, tb):
        curs = self._context_cursors.pop()
        curs.__exit__(exc, value, tb)
    
    # FML.
    def _escape_string(self, value):
        """_escape_string(value) -> str.
        
        A wrapper around mysql_real_escape_string. Takes a bytestring in and 
        produces a bytestring out. Please do not every use this unless mysql
        refuses to parameterize a query; oursql has good support for 
        parameterization which also works consistently with unicode.
        """
        return _oursqlx_escape_string(self.conn, value)
    
    def _escape_unicode_string(self, value):
        """_escape_unicode_stirng(value) -> unicode.
        
        _escape_string that takes unicode in and produces unicode out, using
        the connection's charset. As with _escape_string, please do not use 
        this function.
        """
        charset = self.charset
        return self._escape_string(value.encode(charset)).decode(charset)
