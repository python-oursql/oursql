cdef object bytes_maybe_from_encoding(object s, object encoding, 
        bint allow_none=True):
    if s is None and allow_none:
        return None
    elif PyUnicode_Check(s):
        s = s.encode(encoding)
    return PyBytes_FromObject(s)

cdef char *bytes_or_null(object s):
    if s is None:
        return NULL
    return PyBytes_AS_STRING(s)

cdef unsigned long bitval_from_char_p(unsigned char *s, Py_ssize_t length):
    cdef Py_ssize_t i
    cdef unsigned long ret = 0
    for 0 <= i < length:
        ret = (ret << 8) | s[i]
    return ret

cdef object conversion_info_from_res(MYSQL_RES *res, int fields):
    cdef int i
    cdef MYSQL_FIELD *field
    ret = PyList_New(fields)
    for 0 <= i < fields:
        field = mysql_fetch_field_direct(res, i)
        data = (
            field.type,
            field.flags,
            field.charsetnr)
        Py_INCREF(data)
        PyList_SET_ITEM(ret, i, data)
    return ret

cdef object description_from_res(Connection conn, MYSQL_RES *res, int fields, 
        bint show_table):
    cdef int i
    cdef MYSQL_FIELD *field
    ret = PyList_New(fields)
    # Cache the charset.
    conn.charset
    for 0 <= i < fields:
        field = mysql_fetch_field_direct(res, i)
        name = conn._decode_char_p(field.name)
        if show_table and field.table[0] != 0:
            name = u'%s.%s' % (conn._decode_char_p(field.table), name)
        data = (
            name,
            field.type,
            field.max_length,
            field.length,
            field.length,
            field.decimals,
            field.flags & NOT_NULL_FLAG != NOT_NULL_FLAG)
        Py_INCREF(data)
        PyList_SET_ITEM(ret, i, data)
    return ret

cdef class _DictWhateverMixin:
    def fetchone(self):
        row = super(_DictWhateverMixin, self).fetchone()
        if row is None:
            return None
        ret = {}
        for name, value in zip(self.column_names, row):
            if name in ret:
                if ret[name] != value:
                    raise ProgrammingError('column "%s" appears more than once'
                        ' in output' % name)
            else:
                ret[name] = value
        return ret

_exception_enum_map = {
    _oursqlx_InterfaceError: InterfaceError,
    _oursqlx_DataError: DataError,
    _oursqlx_OperationalError: OperationalError,
    _oursqlx_IntegrityError: IntegrityError,
    _oursqlx_InternalError: InternalError,
    _oursqlx_ProgrammingError: ProgrammingError,
    _oursqlx_NotSupportedError: NotSupportedError,
    _oursqlx_PermissionsError: PermissionsError,
    _oursqlx_UnknownError: UnknownError,
}
def _exception_from_errno(int err):
    return _exception_enum_map[_oursqlx_exc_from_errno(err)]

def _do_warnings_query(Connection conn not None):
    cdef int should_raise = False
    q = _Query(conn, 'SHOW WARNINGS')
    ret = []
    for kind, err, message in q:
        if kind == 'Note':
            kind = Note
        elif kind == 'Warning':
            kind = Warning
            should_raise = True
        elif kind == 'Error':
            kind = _exception_from_errno(err)
            should_raise = True
        else:
            raise InterfaceError('unknown kind of warning: %r' % kind)
        ret.append((kind, (message, err)))
    if should_raise and conn.raise_on_warnings:
        raise CollatedWarningsError('query caused warnings', extra=ret)
    return ret
