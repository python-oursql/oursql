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
    cdef object _charset, _context_cursors
    cdef readonly int use_unicode, autoping, raise_on_warnings
    cdef public object default_cursor
    
    def __cinit__(self, char *host=NULL, char *user=NULL, char *passwd=NULL, *,
            char *db=NULL, unsigned int port=0, char *unix_socket=NULL, 
            connect_timeout=None, read_timeout=None, write_timeout=None, 
            protocol=None, ssl=None, char *read_default_file=NULL, 
            char *read_default_group=NULL, char *init_command=NULL, 
            char *charset_dir=NULL, char *shared_memory_base_name=NULL, 
            bint local_infile=False, bint require_secure_auth=False, 
            bint compress=False, bint report_truncation=True, 
            bint found_rows=True, bint use_unicode=True, str charset='utf8',
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
            mysql_options(self.conn, 
                MYSQL_READ_DEFAULT_FILE, read_default_file)
        if read_default_group:
            mysql_options(self.conn, 
                MYSQL_READ_DEFAULT_GROUP, read_default_group)
        if init_command:
            mysql_options(self.conn, MYSQL_INIT_COMMAND, init_command)
        if charset_dir:
            mysql_options(self.conn, MYSQL_SET_CHARSET_DIR, charset_dir)
        if shared_memory_base_name:
            mysql_options(self.conn, 
                MYSQL_SHARED_MEMORY_BASE_NAME, shared_memory_base_name)
        if local_infile:
            mysql_options(self.conn, MYSQL_OPT_LOCAL_INFILE, NULL)
        if charset is not None:
            mysql_options(self.conn, 
                MYSQL_SET_CHARSET_NAME, PyString_AS_STRING(charset))
        if autoreconnect:
            bool_tmp = True
            mysql_options(self.conn, MYSQL_OPT_RECONNECT, <char *>&bool_tmp)
        if ssl is not None:
            self._setup_ssl_options(**ssl)
        if not mysql_real_connect(self.conn, host, user, passwd, db, port, 
                unix_socket, flags):
            self._raise_error()
        self.use_unicode = use_unicode
        self.autoping = autoping
        if default_cursor is None:
            default_cursor = Cursor
        self.default_cursor = default_cursor
        self.raise_on_warnings = raise_on_warnings
        self._context_cursors = []
    
    def _setup_ssl_options(self, *, char *key=NULL, char *cert=NULL, 
            char *ca=NULL, char *capath=NULL, char *cipher=NULL):
        mysql_ssl_set(self.conn, key, cert, ca, capath, cipher)
    
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
        raise _exception_from_errno(err)(mysql_error(self.conn), err)
    
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
            self._charset = PyString_FromString(
                mysql_character_set_name(self.conn))
            return self._charset
        def __set__(self, value):
            cdef char *svalue
            self._check_closed()
            svalue = PyString_AsString(value)
            if mysql_set_character_set(self.conn, svalue):
                self._raise_error()
            self._charset = value
    
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
            self._check_closed()
            return mysql_get_server_info(self.conn)
    
    property ssl_cipher:
        def __get__(self):
            cdef const_char *res
            self._check_closed()
            res = mysql_get_ssl_cipher(self.conn)
            if not res:
                return None
            return PyString_FromString(res)
    
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
        return self._escape_string(
            value.encode(self.charset)).decode(self.charset)
