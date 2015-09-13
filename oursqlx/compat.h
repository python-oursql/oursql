/* I really don't understand the thought process behind most of mysql. */
#ifdef _WIN32
#  ifdef __MINGW32__
#    include <winsock2.h>
#    include <windows.h>
#  else
#    include "my_global.h"
#    include "pstdint.h"
#  endif
#else
#  include <stdint.h>
#endif
#include "mysql.h"
#include "mysqld_error.h"
#include "errmsg.h"
#include "Python.h"
#if PY_VERSION_HEX < 0x02050000
#  define PyBaseExceptionObject PyObject
#  define PyErr_WarnEx(exc, msg, _) PyErr_Warn(exc, msg)
#  ifndef PY_SSIZE_T_MAX
     typedef int Py_ssize_t;
#    define PY_SSIZE_T_MAX INT_MAX
#    define PY_SSIZE_T_MIN INT_MIN
#  endif
#endif

#if MYSQL_VERSION_ID < 40102
#error "This driver requires at least MySQL 4.1.2."
#endif

enum _oursqlx_exception_type {
    _oursqlx_InterfaceError,
    _oursqlx_DataError,
    _oursqlx_OperationalError,
    _oursqlx_IntegrityError,
    _oursqlx_InternalError,
    _oursqlx_ProgrammingError,
    _oursqlx_NotSupportedError,
    _oursqlx_PermissionsError,
    _oursqlx_UnknownError,
};

my_bool _oursqlx_init_stmt_cursor(MYSQL_STMT *, unsigned long *);
my_bool _oursqlx_stmt_set_prefetch_rows(MYSQL_STMT *, unsigned long *);
int _oursqlx_stmt_cursor_prefetch(MYSQL_STMT *, int *);
int _oursqlx_PyObject_AsReadBuffer(PyObject *, void **, Py_ssize_t *);
enum _oursqlx_exception_type _oursqlx_exc_from_errno(int);
PyObject *_oursqlx_escape_string(MYSQL *, PyObject *);
PyObject *_oursqlx_generate_errno_dict(void);
