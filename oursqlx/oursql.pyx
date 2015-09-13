# cython: language_level=3
"""oursql python bindings for MySQL.

This module is a new, better set of MySQL bindings for python, supporting novel
features like parameterization!
"""

__author__ = 'Aaron Gallagher <habnabit@gmail.com>'
__version__ = '0.9.4'

include "oursql.pxi"
include "nogil.pyx"

PyDateTime_IMPORT

cdef unsigned int UNSIGNED_NUM_FLAG = UNSIGNED_FLAG | NUM_FLAG

cdef union column_data:
    MYSQL_TIME t
    long long ll
    unsigned long long ull
    unsigned long ul
    Py_ssize_t st
    long l
    float f
    double d
    char c
    char dec[65]
    
    int8_t s8
    int16_t s16
    int32_t s32
    int64_t s64
    
    uint8_t u8
    uint16_t u16
    uint32_t u32
    uint64_t u64

cdef union bitfield:
    char c[8]
    uint64_t u64

cdef struct column_output:
    enum_field_types type
    unsigned int flags
    bint is_binary
    unsigned long length
    my_bool is_null
    my_bool error
    column_data buf

import builtins

class Warning(builtins.Warning): pass
class Note(Warning): pass

class Error(builtins.Exception):
    def __init__(self, message, errno=None, extra=None):
        super(Error, self).__init__(errno, message, extra)
        self.errno = errno
        self.extra = extra

class InterfaceError(Error): pass
class DatabaseError(Error): pass
class DataError(DatabaseError): pass
class OperationalError(DatabaseError): pass
class IntegrityError(DatabaseError): pass
class InternalError(DatabaseError): pass
class ProgrammingError(DatabaseError): pass
class CollatedWarningsError(ProgrammingError): pass
class NotSupportedError(DatabaseError): pass
class PermissionsError(DatabaseError): pass

# This exception type is specifically for _exception_from_errno. I think this 
# is a good compromise: if the errno you get isn't valid, return something to 
# indicate that while also being functional.
class UnknownError(Error): pass

cdef class Connection

include "util.pyx"
include "conversions.pyx"
include "connection.pyx"
include "statement.pyx"
include "query.pyx"
include "cursor.pyx"

# The global import lock is held while modules are being imported for the first
# time, so it's threadsafe to call this.
if mysql_library_init(0, NULL, NULL):
    raise InterfaceError('could not initialize mysql')

paramstyle = 'qmark'
threadsafety = 1
apilevel = '2.0'
connect = Connection

cdef class _DBAPITypeObject:
    cdef readonly object values
    
    def __init__(self, *values):
        self.values = frozenset(values)
    
    def __richcmp__(self, other, int op):
        if op == Py_EQ:
            return other in self.values
        elif op == Py_NE:
            return other not in self.values
        else:
            raise TypeError('unorderable types: %r and %r' % (
                type(self), type(other)))
    
    def __repr__(self):
        return '<_DBAPITypeObject representing %r at %#x>' % (
            self.values, id(self))

STRING = _DBAPITypeObject(
    MYSQL_TYPE_ENUM, MYSQL_TYPE_STRING, MYSQL_TYPE_VAR_STRING)
BINARY = _DBAPITypeObject(
    MYSQL_TYPE_BLOB, MYSQL_TYPE_LONG_BLOB, 
    MYSQL_TYPE_MEDIUM_BLOB, MYSQL_TYPE_TINY_BLOB)
NUMBER = _DBAPITypeObject(
    MYSQL_TYPE_DECIMAL, MYSQL_TYPE_DOUBLE, MYSQL_TYPE_FLOAT, MYSQL_TYPE_INT24, 
    MYSQL_TYPE_LONG, MYSQL_TYPE_LONGLONG, MYSQL_TYPE_TINY, MYSQL_TYPE_YEAR)
DATE = _DBAPITypeObject(
    MYSQL_TYPE_DATE, MYSQL_TYPE_NEWDATE)
TIME = _DBAPITypeObject(
    MYSQL_TYPE_TIME)
DATETIME = TIMESTAMP = _DBAPITypeObject(
    MYSQL_TYPE_TIMESTAMP, MYSQL_TYPE_DATETIME)
ROWID = _DBAPITypeObject()

client_info = PyUnicode_FromString(mysql_get_client_info())
errnos = _oursqlx_generate_errno_dict()
