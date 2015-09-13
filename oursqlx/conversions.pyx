import decimal, datetime, time

def _bitval_from_string(s):
    cdef Py_ssize_t length
    cdef unsigned char *ss
    PyString_AsStringAndSize(s, <char **>&ss, &length)
    return bitval_from_char_p(ss, length)

def _datetime_from_string(s):
    tt = time.strptime(s, '%Y-%m-%d %H:%M:%S')
    return datetime.datetime(*tt[:6])

def _date_from_string(s):
    tt = time.strptime(s, '%Y-%m-%d')
    return datetime.date(*tt[:3])

def _time_from_string(s):
    tt = time.strptime(s, '%H:%M:%S')
    return datetime.time(*tt[3:6])

_conversions = {
    MYSQL_TYPE_TINY: int,
    MYSQL_TYPE_SHORT: int,
    MYSQL_TYPE_LONG: long,
    MYSQL_TYPE_FLOAT: float,
    MYSQL_TYPE_DOUBLE: float,
    MYSQL_TYPE_DECIMAL: float,
    MYSQL_TYPE_NEWDECIMAL: float,
    MYSQL_TYPE_LONGLONG: long,
    MYSQL_TYPE_INT24: int,
    MYSQL_TYPE_YEAR: int,
    MYSQL_TYPE_DECIMAL: decimal.Decimal,
    MYSQL_TYPE_NEWDECIMAL: decimal.Decimal,
    MYSQL_TYPE_BIT: _bitval_from_string,
    MYSQL_TYPE_TIMESTAMP: _datetime_from_string,
    MYSQL_TYPE_DATETIME: _datetime_from_string,
    MYSQL_TYPE_DATE: _date_from_string,
    MYSQL_TYPE_TIME: _time_from_string,
    
    # None means to try to decode if we're using unicode and the field isn't 
    # in 'binary' encoding.
    MYSQL_TYPE_BLOB: None,
    MYSQL_TYPE_STRING: None,
    MYSQL_TYPE_VAR_STRING: None,
    MYSQL_TYPE_VARCHAR: None,
    # For consistency with the statement API.
    MYSQL_TYPE_SET: None,
}

Timestamp = datetime.datetime
Date = datetime.date
Time = datetime.time
Binary = buffer

def TimestampFromTicks(ticks):
    """TimestampFromTicks(ticks) -> Timestamp.
    
    Convert a time in seconds since the epoch into a Timestamp.
    """
    return Timestamp(*time.localtime(ticks)[:6])

def DateFromTicks(ticks):
    """DateFromTicks(ticks) -> Date.
    
    Convert a time in seconds since the epoch into a Date.
    """
    return Date(*time.localtime(ticks)[:3])

def TimeFromTicks(ticks):
    """TimeFromTicks(ticks) -> Time.
    
    Convert a time in seconds since the epoch into a Time.
    """
    return Time(*time.localtime(ticks)[3:6])
