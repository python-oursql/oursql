#include "compat.h"

my_bool _oursqlx_init_stmt_cursor(MYSQL_STMT *stmt, unsigned long *cursor_type) {
#if MYSQL_VERSION_ID >= 50002
    *cursor_type = CURSOR_TYPE_READ_ONLY;
    return mysql_stmt_attr_set(stmt, STMT_ATTR_CURSOR_TYPE, cursor_type);
#else
    return 0;
#endif
}

my_bool _oursqlx_stmt_set_prefetch_rows(MYSQL_STMT *stmt, 
        unsigned long *nrows) {
#if MYSQL_VERSION_ID >= 50006
    return mysql_stmt_attr_set(stmt, STMT_ATTR_PREFETCH_ROWS, nrows);
#else
    return 0;
#endif
}

int _oursqlx_stmt_cursor_prefetch(MYSQL_STMT *stmt, int *buffered) {
#if MYSQL_VERSION_ID < 50002
    int ret = mysql_stmt_store_result(stmt);
    if (!ret)
        *buffered = 1;
    return ret;
#else
    return 0;
#endif
}

/* This is JUST for sqlalchemy. I would never have added this if it wasn't
 * unfortunately necessary. :(
 */
PyObject *_oursqlx_escape_string(MYSQL *conn, PyObject *input) {
    char *input_string;
    Py_ssize_t input_size;
    PyObject *output;
    unsigned long output_size;
    if (PyBytes_AsStringAndSize(input, &input_string, &input_size) == -1)
        return NULL;
    if (!(output = PyBytes_FromStringAndSize(NULL, input_size * 2)))
        return NULL;
    output_size = mysql_real_escape_string(
        conn, PyBytes_AS_STRING(output), input_string, input_size);
    if (output_size != input_size * 2)
        _PyBytes_Resize(&output, output_size);
    return output;
}

#include "_exceptions.c"
#include "_errnos.c"
