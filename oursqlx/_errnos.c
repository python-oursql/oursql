
/* generated on Wed Feb 24 14:53:46 2010 */

PyObject *_oursqlx_generate_errno_dict(void) {
    PyObject *ret = NULL, *val = NULL;
    if (!(ret = PyDict_New()))
        return NULL;
    
#ifdef CR_MIN_ERROR
    if (!(val = PyLong_FromLong(CR_MIN_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_MIN_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_MAX_ERROR
    if (!(val = PyLong_FromLong(CR_MAX_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_MAX_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_ERROR_FIRST
    if (!(val = PyLong_FromLong(CR_ERROR_FIRST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_ERROR_FIRST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_UNKNOWN_ERROR
    if (!(val = PyLong_FromLong(CR_UNKNOWN_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_UNKNOWN_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SOCKET_CREATE_ERROR
    if (!(val = PyLong_FromLong(CR_SOCKET_CREATE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SOCKET_CREATE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_CONNECTION_ERROR
    if (!(val = PyLong_FromLong(CR_CONNECTION_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_CONNECTION_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_CONN_HOST_ERROR
    if (!(val = PyLong_FromLong(CR_CONN_HOST_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_CONN_HOST_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_IPSOCK_ERROR
    if (!(val = PyLong_FromLong(CR_IPSOCK_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_IPSOCK_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_UNKNOWN_HOST
    if (!(val = PyLong_FromLong(CR_UNKNOWN_HOST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_UNKNOWN_HOST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SERVER_GONE_ERROR
    if (!(val = PyLong_FromLong(CR_SERVER_GONE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SERVER_GONE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_VERSION_ERROR
    if (!(val = PyLong_FromLong(CR_VERSION_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_VERSION_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_OUT_OF_MEMORY
    if (!(val = PyLong_FromLong(CR_OUT_OF_MEMORY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_OUT_OF_MEMORY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_WRONG_HOST_INFO
    if (!(val = PyLong_FromLong(CR_WRONG_HOST_INFO)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_WRONG_HOST_INFO", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_LOCALHOST_CONNECTION
    if (!(val = PyLong_FromLong(CR_LOCALHOST_CONNECTION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_LOCALHOST_CONNECTION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_TCP_CONNECTION
    if (!(val = PyLong_FromLong(CR_TCP_CONNECTION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_TCP_CONNECTION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SERVER_HANDSHAKE_ERR
    if (!(val = PyLong_FromLong(CR_SERVER_HANDSHAKE_ERR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SERVER_HANDSHAKE_ERR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SERVER_LOST
    if (!(val = PyLong_FromLong(CR_SERVER_LOST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SERVER_LOST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_COMMANDS_OUT_OF_SYNC
    if (!(val = PyLong_FromLong(CR_COMMANDS_OUT_OF_SYNC)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_COMMANDS_OUT_OF_SYNC", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_NAMEDPIPE_CONNECTION
    if (!(val = PyLong_FromLong(CR_NAMEDPIPE_CONNECTION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_NAMEDPIPE_CONNECTION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_NAMEDPIPEWAIT_ERROR
    if (!(val = PyLong_FromLong(CR_NAMEDPIPEWAIT_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_NAMEDPIPEWAIT_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_NAMEDPIPEOPEN_ERROR
    if (!(val = PyLong_FromLong(CR_NAMEDPIPEOPEN_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_NAMEDPIPEOPEN_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_NAMEDPIPESETSTATE_ERROR
    if (!(val = PyLong_FromLong(CR_NAMEDPIPESETSTATE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_NAMEDPIPESETSTATE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_CANT_READ_CHARSET
    if (!(val = PyLong_FromLong(CR_CANT_READ_CHARSET)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_CANT_READ_CHARSET", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_NET_PACKET_TOO_LARGE
    if (!(val = PyLong_FromLong(CR_NET_PACKET_TOO_LARGE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_NET_PACKET_TOO_LARGE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_EMBEDDED_CONNECTION
    if (!(val = PyLong_FromLong(CR_EMBEDDED_CONNECTION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_EMBEDDED_CONNECTION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_PROBE_SLAVE_STATUS
    if (!(val = PyLong_FromLong(CR_PROBE_SLAVE_STATUS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_PROBE_SLAVE_STATUS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_PROBE_SLAVE_HOSTS
    if (!(val = PyLong_FromLong(CR_PROBE_SLAVE_HOSTS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_PROBE_SLAVE_HOSTS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_PROBE_SLAVE_CONNECT
    if (!(val = PyLong_FromLong(CR_PROBE_SLAVE_CONNECT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_PROBE_SLAVE_CONNECT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_PROBE_MASTER_CONNECT
    if (!(val = PyLong_FromLong(CR_PROBE_MASTER_CONNECT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_PROBE_MASTER_CONNECT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SSL_CONNECTION_ERROR
    if (!(val = PyLong_FromLong(CR_SSL_CONNECTION_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SSL_CONNECTION_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_MALFORMED_PACKET
    if (!(val = PyLong_FromLong(CR_MALFORMED_PACKET)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_MALFORMED_PACKET", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_WRONG_LICENSE
    if (!(val = PyLong_FromLong(CR_WRONG_LICENSE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_WRONG_LICENSE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_NULL_POINTER
    if (!(val = PyLong_FromLong(CR_NULL_POINTER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_NULL_POINTER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_NO_PREPARE_STMT
    if (!(val = PyLong_FromLong(CR_NO_PREPARE_STMT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_NO_PREPARE_STMT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_PARAMS_NOT_BOUND
    if (!(val = PyLong_FromLong(CR_PARAMS_NOT_BOUND)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_PARAMS_NOT_BOUND", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_DATA_TRUNCATED
    if (!(val = PyLong_FromLong(CR_DATA_TRUNCATED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_DATA_TRUNCATED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_NO_PARAMETERS_EXISTS
    if (!(val = PyLong_FromLong(CR_NO_PARAMETERS_EXISTS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_NO_PARAMETERS_EXISTS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_INVALID_PARAMETER_NO
    if (!(val = PyLong_FromLong(CR_INVALID_PARAMETER_NO)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_INVALID_PARAMETER_NO", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_INVALID_BUFFER_USE
    if (!(val = PyLong_FromLong(CR_INVALID_BUFFER_USE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_INVALID_BUFFER_USE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_UNSUPPORTED_PARAM_TYPE
    if (!(val = PyLong_FromLong(CR_UNSUPPORTED_PARAM_TYPE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_UNSUPPORTED_PARAM_TYPE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SHARED_MEMORY_CONNECTION
    if (!(val = PyLong_FromLong(CR_SHARED_MEMORY_CONNECTION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SHARED_MEMORY_CONNECTION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SHARED_MEMORY_CONNECT_REQUEST_ERROR
    if (!(val = PyLong_FromLong(CR_SHARED_MEMORY_CONNECT_REQUEST_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SHARED_MEMORY_CONNECT_REQUEST_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SHARED_MEMORY_CONNECT_ANSWER_ERROR
    if (!(val = PyLong_FromLong(CR_SHARED_MEMORY_CONNECT_ANSWER_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SHARED_MEMORY_CONNECT_ANSWER_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SHARED_MEMORY_CONNECT_FILE_MAP_ERROR
    if (!(val = PyLong_FromLong(CR_SHARED_MEMORY_CONNECT_FILE_MAP_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SHARED_MEMORY_CONNECT_FILE_MAP_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SHARED_MEMORY_CONNECT_MAP_ERROR
    if (!(val = PyLong_FromLong(CR_SHARED_MEMORY_CONNECT_MAP_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SHARED_MEMORY_CONNECT_MAP_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SHARED_MEMORY_FILE_MAP_ERROR
    if (!(val = PyLong_FromLong(CR_SHARED_MEMORY_FILE_MAP_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SHARED_MEMORY_FILE_MAP_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SHARED_MEMORY_MAP_ERROR
    if (!(val = PyLong_FromLong(CR_SHARED_MEMORY_MAP_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SHARED_MEMORY_MAP_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SHARED_MEMORY_EVENT_ERROR
    if (!(val = PyLong_FromLong(CR_SHARED_MEMORY_EVENT_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SHARED_MEMORY_EVENT_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SHARED_MEMORY_CONNECT_ABANDONED_ERROR
    if (!(val = PyLong_FromLong(CR_SHARED_MEMORY_CONNECT_ABANDONED_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SHARED_MEMORY_CONNECT_ABANDONED_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SHARED_MEMORY_CONNECT_SET_ERROR
    if (!(val = PyLong_FromLong(CR_SHARED_MEMORY_CONNECT_SET_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SHARED_MEMORY_CONNECT_SET_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_CONN_UNKNOW_PROTOCOL
    if (!(val = PyLong_FromLong(CR_CONN_UNKNOW_PROTOCOL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_CONN_UNKNOW_PROTOCOL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_INVALID_CONN_HANDLE
    if (!(val = PyLong_FromLong(CR_INVALID_CONN_HANDLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_INVALID_CONN_HANDLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SECURE_AUTH
    if (!(val = PyLong_FromLong(CR_SECURE_AUTH)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SECURE_AUTH", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_FETCH_CANCELED
    if (!(val = PyLong_FromLong(CR_FETCH_CANCELED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_FETCH_CANCELED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_NO_DATA
    if (!(val = PyLong_FromLong(CR_NO_DATA)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_NO_DATA", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_NO_STMT_METADATA
    if (!(val = PyLong_FromLong(CR_NO_STMT_METADATA)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_NO_STMT_METADATA", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_NO_RESULT_SET
    if (!(val = PyLong_FromLong(CR_NO_RESULT_SET)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_NO_RESULT_SET", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_NOT_IMPLEMENTED
    if (!(val = PyLong_FromLong(CR_NOT_IMPLEMENTED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_NOT_IMPLEMENTED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_SERVER_LOST_EXTENDED
    if (!(val = PyLong_FromLong(CR_SERVER_LOST_EXTENDED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_SERVER_LOST_EXTENDED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_STMT_CLOSED
    if (!(val = PyLong_FromLong(CR_STMT_CLOSED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_STMT_CLOSED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_NEW_STMT_METADATA
    if (!(val = PyLong_FromLong(CR_NEW_STMT_METADATA)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_NEW_STMT_METADATA", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef CR_ERROR_LAST
    if (!(val = PyLong_FromLong(CR_ERROR_LAST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "CR_ERROR_LAST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ERROR_FIRST
    if (!(val = PyLong_FromLong(ER_ERROR_FIRST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ERROR_FIRST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_HASHCHK
    if (!(val = PyLong_FromLong(ER_HASHCHK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_HASHCHK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NISAMCHK
    if (!(val = PyLong_FromLong(ER_NISAMCHK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NISAMCHK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO
    if (!(val = PyLong_FromLong(ER_NO)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_YES
    if (!(val = PyLong_FromLong(ER_YES)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_YES", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_CREATE_FILE
    if (!(val = PyLong_FromLong(ER_CANT_CREATE_FILE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_CREATE_FILE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_CREATE_TABLE
    if (!(val = PyLong_FromLong(ER_CANT_CREATE_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_CREATE_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_CREATE_DB
    if (!(val = PyLong_FromLong(ER_CANT_CREATE_DB)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_CREATE_DB", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DB_CREATE_EXISTS
    if (!(val = PyLong_FromLong(ER_DB_CREATE_EXISTS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DB_CREATE_EXISTS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DB_DROP_EXISTS
    if (!(val = PyLong_FromLong(ER_DB_DROP_EXISTS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DB_DROP_EXISTS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DB_DROP_DELETE
    if (!(val = PyLong_FromLong(ER_DB_DROP_DELETE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DB_DROP_DELETE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DB_DROP_RMDIR
    if (!(val = PyLong_FromLong(ER_DB_DROP_RMDIR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DB_DROP_RMDIR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_DELETE_FILE
    if (!(val = PyLong_FromLong(ER_CANT_DELETE_FILE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_DELETE_FILE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_FIND_SYSTEM_REC
    if (!(val = PyLong_FromLong(ER_CANT_FIND_SYSTEM_REC)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_FIND_SYSTEM_REC", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_GET_STAT
    if (!(val = PyLong_FromLong(ER_CANT_GET_STAT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_GET_STAT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_GET_WD
    if (!(val = PyLong_FromLong(ER_CANT_GET_WD)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_GET_WD", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_LOCK
    if (!(val = PyLong_FromLong(ER_CANT_LOCK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_LOCK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_OPEN_FILE
    if (!(val = PyLong_FromLong(ER_CANT_OPEN_FILE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_OPEN_FILE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FILE_NOT_FOUND
    if (!(val = PyLong_FromLong(ER_FILE_NOT_FOUND)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FILE_NOT_FOUND", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_READ_DIR
    if (!(val = PyLong_FromLong(ER_CANT_READ_DIR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_READ_DIR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_SET_WD
    if (!(val = PyLong_FromLong(ER_CANT_SET_WD)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_SET_WD", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CHECKREAD
    if (!(val = PyLong_FromLong(ER_CHECKREAD)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CHECKREAD", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DISK_FULL
    if (!(val = PyLong_FromLong(ER_DISK_FULL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DISK_FULL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DUP_KEY
    if (!(val = PyLong_FromLong(ER_DUP_KEY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DUP_KEY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ERROR_ON_CLOSE
    if (!(val = PyLong_FromLong(ER_ERROR_ON_CLOSE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ERROR_ON_CLOSE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ERROR_ON_READ
    if (!(val = PyLong_FromLong(ER_ERROR_ON_READ)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ERROR_ON_READ", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ERROR_ON_RENAME
    if (!(val = PyLong_FromLong(ER_ERROR_ON_RENAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ERROR_ON_RENAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ERROR_ON_WRITE
    if (!(val = PyLong_FromLong(ER_ERROR_ON_WRITE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ERROR_ON_WRITE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FILE_USED
    if (!(val = PyLong_FromLong(ER_FILE_USED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FILE_USED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FILSORT_ABORT
    if (!(val = PyLong_FromLong(ER_FILSORT_ABORT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FILSORT_ABORT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FORM_NOT_FOUND
    if (!(val = PyLong_FromLong(ER_FORM_NOT_FOUND)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FORM_NOT_FOUND", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_GET_ERRNO
    if (!(val = PyLong_FromLong(ER_GET_ERRNO)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_GET_ERRNO", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ILLEGAL_HA
    if (!(val = PyLong_FromLong(ER_ILLEGAL_HA)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ILLEGAL_HA", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_KEY_NOT_FOUND
    if (!(val = PyLong_FromLong(ER_KEY_NOT_FOUND)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_KEY_NOT_FOUND", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NOT_FORM_FILE
    if (!(val = PyLong_FromLong(ER_NOT_FORM_FILE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NOT_FORM_FILE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NOT_KEYFILE
    if (!(val = PyLong_FromLong(ER_NOT_KEYFILE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NOT_KEYFILE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_OLD_KEYFILE
    if (!(val = PyLong_FromLong(ER_OLD_KEYFILE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_OLD_KEYFILE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_OPEN_AS_READONLY
    if (!(val = PyLong_FromLong(ER_OPEN_AS_READONLY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_OPEN_AS_READONLY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_OUTOFMEMORY
    if (!(val = PyLong_FromLong(ER_OUTOFMEMORY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_OUTOFMEMORY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_OUT_OF_SORTMEMORY
    if (!(val = PyLong_FromLong(ER_OUT_OF_SORTMEMORY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_OUT_OF_SORTMEMORY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNEXPECTED_EOF
    if (!(val = PyLong_FromLong(ER_UNEXPECTED_EOF)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNEXPECTED_EOF", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CON_COUNT_ERROR
    if (!(val = PyLong_FromLong(ER_CON_COUNT_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CON_COUNT_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_OUT_OF_RESOURCES
    if (!(val = PyLong_FromLong(ER_OUT_OF_RESOURCES)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_OUT_OF_RESOURCES", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BAD_HOST_ERROR
    if (!(val = PyLong_FromLong(ER_BAD_HOST_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BAD_HOST_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_HANDSHAKE_ERROR
    if (!(val = PyLong_FromLong(ER_HANDSHAKE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_HANDSHAKE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DBACCESS_DENIED_ERROR
    if (!(val = PyLong_FromLong(ER_DBACCESS_DENIED_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DBACCESS_DENIED_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ACCESS_DENIED_ERROR
    if (!(val = PyLong_FromLong(ER_ACCESS_DENIED_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ACCESS_DENIED_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_DB_ERROR
    if (!(val = PyLong_FromLong(ER_NO_DB_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_DB_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNKNOWN_COM_ERROR
    if (!(val = PyLong_FromLong(ER_UNKNOWN_COM_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNKNOWN_COM_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BAD_NULL_ERROR
    if (!(val = PyLong_FromLong(ER_BAD_NULL_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BAD_NULL_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BAD_DB_ERROR
    if (!(val = PyLong_FromLong(ER_BAD_DB_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BAD_DB_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLE_EXISTS_ERROR
    if (!(val = PyLong_FromLong(ER_TABLE_EXISTS_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLE_EXISTS_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BAD_TABLE_ERROR
    if (!(val = PyLong_FromLong(ER_BAD_TABLE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BAD_TABLE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NON_UNIQ_ERROR
    if (!(val = PyLong_FromLong(ER_NON_UNIQ_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NON_UNIQ_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SERVER_SHUTDOWN
    if (!(val = PyLong_FromLong(ER_SERVER_SHUTDOWN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SERVER_SHUTDOWN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BAD_FIELD_ERROR
    if (!(val = PyLong_FromLong(ER_BAD_FIELD_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BAD_FIELD_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_FIELD_WITH_GROUP
    if (!(val = PyLong_FromLong(ER_WRONG_FIELD_WITH_GROUP)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_FIELD_WITH_GROUP", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_GROUP_FIELD
    if (!(val = PyLong_FromLong(ER_WRONG_GROUP_FIELD)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_GROUP_FIELD", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_SUM_SELECT
    if (!(val = PyLong_FromLong(ER_WRONG_SUM_SELECT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_SUM_SELECT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_VALUE_COUNT
    if (!(val = PyLong_FromLong(ER_WRONG_VALUE_COUNT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_VALUE_COUNT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_LONG_IDENT
    if (!(val = PyLong_FromLong(ER_TOO_LONG_IDENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_LONG_IDENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DUP_FIELDNAME
    if (!(val = PyLong_FromLong(ER_DUP_FIELDNAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DUP_FIELDNAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DUP_KEYNAME
    if (!(val = PyLong_FromLong(ER_DUP_KEYNAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DUP_KEYNAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DUP_ENTRY
    if (!(val = PyLong_FromLong(ER_DUP_ENTRY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DUP_ENTRY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_FIELD_SPEC
    if (!(val = PyLong_FromLong(ER_WRONG_FIELD_SPEC)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_FIELD_SPEC", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARSE_ERROR
    if (!(val = PyLong_FromLong(ER_PARSE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARSE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EMPTY_QUERY
    if (!(val = PyLong_FromLong(ER_EMPTY_QUERY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EMPTY_QUERY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NONUNIQ_TABLE
    if (!(val = PyLong_FromLong(ER_NONUNIQ_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NONUNIQ_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_INVALID_DEFAULT
    if (!(val = PyLong_FromLong(ER_INVALID_DEFAULT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_INVALID_DEFAULT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_MULTIPLE_PRI_KEY
    if (!(val = PyLong_FromLong(ER_MULTIPLE_PRI_KEY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_MULTIPLE_PRI_KEY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_MANY_KEYS
    if (!(val = PyLong_FromLong(ER_TOO_MANY_KEYS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_MANY_KEYS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_MANY_KEY_PARTS
    if (!(val = PyLong_FromLong(ER_TOO_MANY_KEY_PARTS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_MANY_KEY_PARTS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_LONG_KEY
    if (!(val = PyLong_FromLong(ER_TOO_LONG_KEY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_LONG_KEY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_KEY_COLUMN_DOES_NOT_EXITS
    if (!(val = PyLong_FromLong(ER_KEY_COLUMN_DOES_NOT_EXITS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_KEY_COLUMN_DOES_NOT_EXITS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BLOB_USED_AS_KEY
    if (!(val = PyLong_FromLong(ER_BLOB_USED_AS_KEY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BLOB_USED_AS_KEY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_BIG_FIELDLENGTH
    if (!(val = PyLong_FromLong(ER_TOO_BIG_FIELDLENGTH)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_BIG_FIELDLENGTH", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_AUTO_KEY
    if (!(val = PyLong_FromLong(ER_WRONG_AUTO_KEY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_AUTO_KEY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_READY
    if (!(val = PyLong_FromLong(ER_READY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_READY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NORMAL_SHUTDOWN
    if (!(val = PyLong_FromLong(ER_NORMAL_SHUTDOWN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NORMAL_SHUTDOWN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_GOT_SIGNAL
    if (!(val = PyLong_FromLong(ER_GOT_SIGNAL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_GOT_SIGNAL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SHUTDOWN_COMPLETE
    if (!(val = PyLong_FromLong(ER_SHUTDOWN_COMPLETE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SHUTDOWN_COMPLETE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FORCING_CLOSE
    if (!(val = PyLong_FromLong(ER_FORCING_CLOSE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FORCING_CLOSE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_IPSOCK_ERROR
    if (!(val = PyLong_FromLong(ER_IPSOCK_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_IPSOCK_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_SUCH_INDEX
    if (!(val = PyLong_FromLong(ER_NO_SUCH_INDEX)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_SUCH_INDEX", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_FIELD_TERMINATORS
    if (!(val = PyLong_FromLong(ER_WRONG_FIELD_TERMINATORS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_FIELD_TERMINATORS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BLOBS_AND_NO_TERMINATED
    if (!(val = PyLong_FromLong(ER_BLOBS_AND_NO_TERMINATED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BLOBS_AND_NO_TERMINATED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TEXTFILE_NOT_READABLE
    if (!(val = PyLong_FromLong(ER_TEXTFILE_NOT_READABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TEXTFILE_NOT_READABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FILE_EXISTS_ERROR
    if (!(val = PyLong_FromLong(ER_FILE_EXISTS_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FILE_EXISTS_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LOAD_INFO
    if (!(val = PyLong_FromLong(ER_LOAD_INFO)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LOAD_INFO", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ALTER_INFO
    if (!(val = PyLong_FromLong(ER_ALTER_INFO)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ALTER_INFO", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_SUB_KEY
    if (!(val = PyLong_FromLong(ER_WRONG_SUB_KEY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_SUB_KEY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_REMOVE_ALL_FIELDS
    if (!(val = PyLong_FromLong(ER_CANT_REMOVE_ALL_FIELDS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_REMOVE_ALL_FIELDS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_DROP_FIELD_OR_KEY
    if (!(val = PyLong_FromLong(ER_CANT_DROP_FIELD_OR_KEY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_DROP_FIELD_OR_KEY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_INSERT_INFO
    if (!(val = PyLong_FromLong(ER_INSERT_INFO)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_INSERT_INFO", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UPDATE_TABLE_USED
    if (!(val = PyLong_FromLong(ER_UPDATE_TABLE_USED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UPDATE_TABLE_USED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_SUCH_THREAD
    if (!(val = PyLong_FromLong(ER_NO_SUCH_THREAD)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_SUCH_THREAD", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_KILL_DENIED_ERROR
    if (!(val = PyLong_FromLong(ER_KILL_DENIED_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_KILL_DENIED_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_TABLES_USED
    if (!(val = PyLong_FromLong(ER_NO_TABLES_USED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_TABLES_USED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_BIG_SET
    if (!(val = PyLong_FromLong(ER_TOO_BIG_SET)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_BIG_SET", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_UNIQUE_LOGFILE
    if (!(val = PyLong_FromLong(ER_NO_UNIQUE_LOGFILE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_UNIQUE_LOGFILE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLE_NOT_LOCKED_FOR_WRITE
    if (!(val = PyLong_FromLong(ER_TABLE_NOT_LOCKED_FOR_WRITE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLE_NOT_LOCKED_FOR_WRITE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLE_NOT_LOCKED
    if (!(val = PyLong_FromLong(ER_TABLE_NOT_LOCKED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLE_NOT_LOCKED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BLOB_CANT_HAVE_DEFAULT
    if (!(val = PyLong_FromLong(ER_BLOB_CANT_HAVE_DEFAULT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BLOB_CANT_HAVE_DEFAULT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_DB_NAME
    if (!(val = PyLong_FromLong(ER_WRONG_DB_NAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_DB_NAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_TABLE_NAME
    if (!(val = PyLong_FromLong(ER_WRONG_TABLE_NAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_TABLE_NAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_BIG_SELECT
    if (!(val = PyLong_FromLong(ER_TOO_BIG_SELECT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_BIG_SELECT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNKNOWN_ERROR
    if (!(val = PyLong_FromLong(ER_UNKNOWN_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNKNOWN_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNKNOWN_PROCEDURE
    if (!(val = PyLong_FromLong(ER_UNKNOWN_PROCEDURE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNKNOWN_PROCEDURE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_PARAMCOUNT_TO_PROCEDURE
    if (!(val = PyLong_FromLong(ER_WRONG_PARAMCOUNT_TO_PROCEDURE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_PARAMCOUNT_TO_PROCEDURE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_PARAMETERS_TO_PROCEDURE
    if (!(val = PyLong_FromLong(ER_WRONG_PARAMETERS_TO_PROCEDURE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_PARAMETERS_TO_PROCEDURE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNKNOWN_TABLE
    if (!(val = PyLong_FromLong(ER_UNKNOWN_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNKNOWN_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FIELD_SPECIFIED_TWICE
    if (!(val = PyLong_FromLong(ER_FIELD_SPECIFIED_TWICE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FIELD_SPECIFIED_TWICE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_INVALID_GROUP_FUNC_USE
    if (!(val = PyLong_FromLong(ER_INVALID_GROUP_FUNC_USE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_INVALID_GROUP_FUNC_USE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNSUPPORTED_EXTENSION
    if (!(val = PyLong_FromLong(ER_UNSUPPORTED_EXTENSION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNSUPPORTED_EXTENSION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLE_MUST_HAVE_COLUMNS
    if (!(val = PyLong_FromLong(ER_TABLE_MUST_HAVE_COLUMNS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLE_MUST_HAVE_COLUMNS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_RECORD_FILE_FULL
    if (!(val = PyLong_FromLong(ER_RECORD_FILE_FULL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_RECORD_FILE_FULL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNKNOWN_CHARACTER_SET
    if (!(val = PyLong_FromLong(ER_UNKNOWN_CHARACTER_SET)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNKNOWN_CHARACTER_SET", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_MANY_TABLES
    if (!(val = PyLong_FromLong(ER_TOO_MANY_TABLES)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_MANY_TABLES", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_MANY_FIELDS
    if (!(val = PyLong_FromLong(ER_TOO_MANY_FIELDS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_MANY_FIELDS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_BIG_ROWSIZE
    if (!(val = PyLong_FromLong(ER_TOO_BIG_ROWSIZE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_BIG_ROWSIZE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_STACK_OVERRUN
    if (!(val = PyLong_FromLong(ER_STACK_OVERRUN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_STACK_OVERRUN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_OUTER_JOIN
    if (!(val = PyLong_FromLong(ER_WRONG_OUTER_JOIN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_OUTER_JOIN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NULL_COLUMN_IN_INDEX
    if (!(val = PyLong_FromLong(ER_NULL_COLUMN_IN_INDEX)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NULL_COLUMN_IN_INDEX", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_FIND_UDF
    if (!(val = PyLong_FromLong(ER_CANT_FIND_UDF)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_FIND_UDF", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_INITIALIZE_UDF
    if (!(val = PyLong_FromLong(ER_CANT_INITIALIZE_UDF)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_INITIALIZE_UDF", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UDF_NO_PATHS
    if (!(val = PyLong_FromLong(ER_UDF_NO_PATHS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UDF_NO_PATHS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UDF_EXISTS
    if (!(val = PyLong_FromLong(ER_UDF_EXISTS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UDF_EXISTS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_OPEN_LIBRARY
    if (!(val = PyLong_FromLong(ER_CANT_OPEN_LIBRARY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_OPEN_LIBRARY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_FIND_DL_ENTRY
    if (!(val = PyLong_FromLong(ER_CANT_FIND_DL_ENTRY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_FIND_DL_ENTRY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FUNCTION_NOT_DEFINED
    if (!(val = PyLong_FromLong(ER_FUNCTION_NOT_DEFINED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FUNCTION_NOT_DEFINED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_HOST_IS_BLOCKED
    if (!(val = PyLong_FromLong(ER_HOST_IS_BLOCKED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_HOST_IS_BLOCKED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_HOST_NOT_PRIVILEGED
    if (!(val = PyLong_FromLong(ER_HOST_NOT_PRIVILEGED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_HOST_NOT_PRIVILEGED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PASSWORD_ANONYMOUS_USER
    if (!(val = PyLong_FromLong(ER_PASSWORD_ANONYMOUS_USER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PASSWORD_ANONYMOUS_USER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PASSWORD_NOT_ALLOWED
    if (!(val = PyLong_FromLong(ER_PASSWORD_NOT_ALLOWED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PASSWORD_NOT_ALLOWED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PASSWORD_NO_MATCH
    if (!(val = PyLong_FromLong(ER_PASSWORD_NO_MATCH)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PASSWORD_NO_MATCH", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UPDATE_INFO
    if (!(val = PyLong_FromLong(ER_UPDATE_INFO)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UPDATE_INFO", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_CREATE_THREAD
    if (!(val = PyLong_FromLong(ER_CANT_CREATE_THREAD)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_CREATE_THREAD", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_VALUE_COUNT_ON_ROW
    if (!(val = PyLong_FromLong(ER_WRONG_VALUE_COUNT_ON_ROW)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_VALUE_COUNT_ON_ROW", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_REOPEN_TABLE
    if (!(val = PyLong_FromLong(ER_CANT_REOPEN_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_REOPEN_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_INVALID_USE_OF_NULL
    if (!(val = PyLong_FromLong(ER_INVALID_USE_OF_NULL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_INVALID_USE_OF_NULL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_REGEXP_ERROR
    if (!(val = PyLong_FromLong(ER_REGEXP_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_REGEXP_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_MIX_OF_GROUP_FUNC_AND_FIELDS
    if (!(val = PyLong_FromLong(ER_MIX_OF_GROUP_FUNC_AND_FIELDS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_MIX_OF_GROUP_FUNC_AND_FIELDS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NONEXISTING_GRANT
    if (!(val = PyLong_FromLong(ER_NONEXISTING_GRANT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NONEXISTING_GRANT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLEACCESS_DENIED_ERROR
    if (!(val = PyLong_FromLong(ER_TABLEACCESS_DENIED_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLEACCESS_DENIED_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_COLUMNACCESS_DENIED_ERROR
    if (!(val = PyLong_FromLong(ER_COLUMNACCESS_DENIED_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_COLUMNACCESS_DENIED_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ILLEGAL_GRANT_FOR_TABLE
    if (!(val = PyLong_FromLong(ER_ILLEGAL_GRANT_FOR_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ILLEGAL_GRANT_FOR_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_GRANT_WRONG_HOST_OR_USER
    if (!(val = PyLong_FromLong(ER_GRANT_WRONG_HOST_OR_USER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_GRANT_WRONG_HOST_OR_USER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_SUCH_TABLE
    if (!(val = PyLong_FromLong(ER_NO_SUCH_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_SUCH_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NONEXISTING_TABLE_GRANT
    if (!(val = PyLong_FromLong(ER_NONEXISTING_TABLE_GRANT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NONEXISTING_TABLE_GRANT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NOT_ALLOWED_COMMAND
    if (!(val = PyLong_FromLong(ER_NOT_ALLOWED_COMMAND)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NOT_ALLOWED_COMMAND", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SYNTAX_ERROR
    if (!(val = PyLong_FromLong(ER_SYNTAX_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SYNTAX_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DELAYED_CANT_CHANGE_LOCK
    if (!(val = PyLong_FromLong(ER_DELAYED_CANT_CHANGE_LOCK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DELAYED_CANT_CHANGE_LOCK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_MANY_DELAYED_THREADS
    if (!(val = PyLong_FromLong(ER_TOO_MANY_DELAYED_THREADS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_MANY_DELAYED_THREADS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ABORTING_CONNECTION
    if (!(val = PyLong_FromLong(ER_ABORTING_CONNECTION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ABORTING_CONNECTION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NET_PACKET_TOO_LARGE
    if (!(val = PyLong_FromLong(ER_NET_PACKET_TOO_LARGE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NET_PACKET_TOO_LARGE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NET_READ_ERROR_FROM_PIPE
    if (!(val = PyLong_FromLong(ER_NET_READ_ERROR_FROM_PIPE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NET_READ_ERROR_FROM_PIPE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NET_FCNTL_ERROR
    if (!(val = PyLong_FromLong(ER_NET_FCNTL_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NET_FCNTL_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NET_PACKETS_OUT_OF_ORDER
    if (!(val = PyLong_FromLong(ER_NET_PACKETS_OUT_OF_ORDER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NET_PACKETS_OUT_OF_ORDER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NET_UNCOMPRESS_ERROR
    if (!(val = PyLong_FromLong(ER_NET_UNCOMPRESS_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NET_UNCOMPRESS_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NET_READ_ERROR
    if (!(val = PyLong_FromLong(ER_NET_READ_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NET_READ_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NET_READ_INTERRUPTED
    if (!(val = PyLong_FromLong(ER_NET_READ_INTERRUPTED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NET_READ_INTERRUPTED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NET_ERROR_ON_WRITE
    if (!(val = PyLong_FromLong(ER_NET_ERROR_ON_WRITE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NET_ERROR_ON_WRITE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NET_WRITE_INTERRUPTED
    if (!(val = PyLong_FromLong(ER_NET_WRITE_INTERRUPTED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NET_WRITE_INTERRUPTED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_LONG_STRING
    if (!(val = PyLong_FromLong(ER_TOO_LONG_STRING)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_LONG_STRING", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLE_CANT_HANDLE_BLOB
    if (!(val = PyLong_FromLong(ER_TABLE_CANT_HANDLE_BLOB)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLE_CANT_HANDLE_BLOB", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLE_CANT_HANDLE_AUTO_INCREMENT
    if (!(val = PyLong_FromLong(ER_TABLE_CANT_HANDLE_AUTO_INCREMENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLE_CANT_HANDLE_AUTO_INCREMENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DELAYED_INSERT_TABLE_LOCKED
    if (!(val = PyLong_FromLong(ER_DELAYED_INSERT_TABLE_LOCKED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DELAYED_INSERT_TABLE_LOCKED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_COLUMN_NAME
    if (!(val = PyLong_FromLong(ER_WRONG_COLUMN_NAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_COLUMN_NAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_KEY_COLUMN
    if (!(val = PyLong_FromLong(ER_WRONG_KEY_COLUMN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_KEY_COLUMN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_MRG_TABLE
    if (!(val = PyLong_FromLong(ER_WRONG_MRG_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_MRG_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DUP_UNIQUE
    if (!(val = PyLong_FromLong(ER_DUP_UNIQUE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DUP_UNIQUE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BLOB_KEY_WITHOUT_LENGTH
    if (!(val = PyLong_FromLong(ER_BLOB_KEY_WITHOUT_LENGTH)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BLOB_KEY_WITHOUT_LENGTH", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PRIMARY_CANT_HAVE_NULL
    if (!(val = PyLong_FromLong(ER_PRIMARY_CANT_HAVE_NULL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PRIMARY_CANT_HAVE_NULL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_MANY_ROWS
    if (!(val = PyLong_FromLong(ER_TOO_MANY_ROWS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_MANY_ROWS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_REQUIRES_PRIMARY_KEY
    if (!(val = PyLong_FromLong(ER_REQUIRES_PRIMARY_KEY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_REQUIRES_PRIMARY_KEY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_RAID_COMPILED
    if (!(val = PyLong_FromLong(ER_NO_RAID_COMPILED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_RAID_COMPILED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UPDATE_WITHOUT_KEY_IN_SAFE_MODE
    if (!(val = PyLong_FromLong(ER_UPDATE_WITHOUT_KEY_IN_SAFE_MODE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UPDATE_WITHOUT_KEY_IN_SAFE_MODE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_KEY_DOES_NOT_EXITS
    if (!(val = PyLong_FromLong(ER_KEY_DOES_NOT_EXITS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_KEY_DOES_NOT_EXITS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CHECK_NO_SUCH_TABLE
    if (!(val = PyLong_FromLong(ER_CHECK_NO_SUCH_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CHECK_NO_SUCH_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CHECK_NOT_IMPLEMENTED
    if (!(val = PyLong_FromLong(ER_CHECK_NOT_IMPLEMENTED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CHECK_NOT_IMPLEMENTED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_DO_THIS_DURING_AN_TRANSACTION
    if (!(val = PyLong_FromLong(ER_CANT_DO_THIS_DURING_AN_TRANSACTION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_DO_THIS_DURING_AN_TRANSACTION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ERROR_DURING_COMMIT
    if (!(val = PyLong_FromLong(ER_ERROR_DURING_COMMIT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ERROR_DURING_COMMIT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ERROR_DURING_ROLLBACK
    if (!(val = PyLong_FromLong(ER_ERROR_DURING_ROLLBACK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ERROR_DURING_ROLLBACK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ERROR_DURING_FLUSH_LOGS
    if (!(val = PyLong_FromLong(ER_ERROR_DURING_FLUSH_LOGS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ERROR_DURING_FLUSH_LOGS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ERROR_DURING_CHECKPOINT
    if (!(val = PyLong_FromLong(ER_ERROR_DURING_CHECKPOINT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ERROR_DURING_CHECKPOINT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NEW_ABORTING_CONNECTION
    if (!(val = PyLong_FromLong(ER_NEW_ABORTING_CONNECTION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NEW_ABORTING_CONNECTION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DUMP_NOT_IMPLEMENTED
    if (!(val = PyLong_FromLong(ER_DUMP_NOT_IMPLEMENTED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DUMP_NOT_IMPLEMENTED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FLUSH_MASTER_BINLOG_CLOSED
    if (!(val = PyLong_FromLong(ER_FLUSH_MASTER_BINLOG_CLOSED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FLUSH_MASTER_BINLOG_CLOSED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_INDEX_REBUILD
    if (!(val = PyLong_FromLong(ER_INDEX_REBUILD)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_INDEX_REBUILD", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_MASTER
    if (!(val = PyLong_FromLong(ER_MASTER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_MASTER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_MASTER_NET_READ
    if (!(val = PyLong_FromLong(ER_MASTER_NET_READ)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_MASTER_NET_READ", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_MASTER_NET_WRITE
    if (!(val = PyLong_FromLong(ER_MASTER_NET_WRITE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_MASTER_NET_WRITE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FT_MATCHING_KEY_NOT_FOUND
    if (!(val = PyLong_FromLong(ER_FT_MATCHING_KEY_NOT_FOUND)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FT_MATCHING_KEY_NOT_FOUND", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LOCK_OR_ACTIVE_TRANSACTION
    if (!(val = PyLong_FromLong(ER_LOCK_OR_ACTIVE_TRANSACTION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LOCK_OR_ACTIVE_TRANSACTION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNKNOWN_SYSTEM_VARIABLE
    if (!(val = PyLong_FromLong(ER_UNKNOWN_SYSTEM_VARIABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNKNOWN_SYSTEM_VARIABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CRASHED_ON_USAGE
    if (!(val = PyLong_FromLong(ER_CRASHED_ON_USAGE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CRASHED_ON_USAGE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CRASHED_ON_REPAIR
    if (!(val = PyLong_FromLong(ER_CRASHED_ON_REPAIR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CRASHED_ON_REPAIR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARNING_NOT_COMPLETE_ROLLBACK
    if (!(val = PyLong_FromLong(ER_WARNING_NOT_COMPLETE_ROLLBACK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARNING_NOT_COMPLETE_ROLLBACK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRANS_CACHE_FULL
    if (!(val = PyLong_FromLong(ER_TRANS_CACHE_FULL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRANS_CACHE_FULL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_MUST_STOP
    if (!(val = PyLong_FromLong(ER_SLAVE_MUST_STOP)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_MUST_STOP", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_NOT_RUNNING
    if (!(val = PyLong_FromLong(ER_SLAVE_NOT_RUNNING)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_NOT_RUNNING", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BAD_SLAVE
    if (!(val = PyLong_FromLong(ER_BAD_SLAVE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BAD_SLAVE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_MASTER_INFO
    if (!(val = PyLong_FromLong(ER_MASTER_INFO)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_MASTER_INFO", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_THREAD
    if (!(val = PyLong_FromLong(ER_SLAVE_THREAD)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_THREAD", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_MANY_USER_CONNECTIONS
    if (!(val = PyLong_FromLong(ER_TOO_MANY_USER_CONNECTIONS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_MANY_USER_CONNECTIONS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SET_CONSTANTS_ONLY
    if (!(val = PyLong_FromLong(ER_SET_CONSTANTS_ONLY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SET_CONSTANTS_ONLY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LOCK_WAIT_TIMEOUT
    if (!(val = PyLong_FromLong(ER_LOCK_WAIT_TIMEOUT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LOCK_WAIT_TIMEOUT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LOCK_TABLE_FULL
    if (!(val = PyLong_FromLong(ER_LOCK_TABLE_FULL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LOCK_TABLE_FULL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_READ_ONLY_TRANSACTION
    if (!(val = PyLong_FromLong(ER_READ_ONLY_TRANSACTION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_READ_ONLY_TRANSACTION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DROP_DB_WITH_READ_LOCK
    if (!(val = PyLong_FromLong(ER_DROP_DB_WITH_READ_LOCK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DROP_DB_WITH_READ_LOCK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CREATE_DB_WITH_READ_LOCK
    if (!(val = PyLong_FromLong(ER_CREATE_DB_WITH_READ_LOCK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CREATE_DB_WITH_READ_LOCK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_ARGUMENTS
    if (!(val = PyLong_FromLong(ER_WRONG_ARGUMENTS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_ARGUMENTS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_PERMISSION_TO_CREATE_USER
    if (!(val = PyLong_FromLong(ER_NO_PERMISSION_TO_CREATE_USER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_PERMISSION_TO_CREATE_USER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNION_TABLES_IN_DIFFERENT_DIR
    if (!(val = PyLong_FromLong(ER_UNION_TABLES_IN_DIFFERENT_DIR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNION_TABLES_IN_DIFFERENT_DIR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LOCK_DEADLOCK
    if (!(val = PyLong_FromLong(ER_LOCK_DEADLOCK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LOCK_DEADLOCK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLE_CANT_HANDLE_FT
    if (!(val = PyLong_FromLong(ER_TABLE_CANT_HANDLE_FT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLE_CANT_HANDLE_FT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANNOT_ADD_FOREIGN
    if (!(val = PyLong_FromLong(ER_CANNOT_ADD_FOREIGN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANNOT_ADD_FOREIGN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_REFERENCED_ROW
    if (!(val = PyLong_FromLong(ER_NO_REFERENCED_ROW)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_REFERENCED_ROW", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ROW_IS_REFERENCED
    if (!(val = PyLong_FromLong(ER_ROW_IS_REFERENCED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ROW_IS_REFERENCED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CONNECT_TO_MASTER
    if (!(val = PyLong_FromLong(ER_CONNECT_TO_MASTER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CONNECT_TO_MASTER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_QUERY_ON_MASTER
    if (!(val = PyLong_FromLong(ER_QUERY_ON_MASTER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_QUERY_ON_MASTER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ERROR_WHEN_EXECUTING_COMMAND
    if (!(val = PyLong_FromLong(ER_ERROR_WHEN_EXECUTING_COMMAND)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ERROR_WHEN_EXECUTING_COMMAND", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_USAGE
    if (!(val = PyLong_FromLong(ER_WRONG_USAGE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_USAGE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_NUMBER_OF_COLUMNS_IN_SELECT
    if (!(val = PyLong_FromLong(ER_WRONG_NUMBER_OF_COLUMNS_IN_SELECT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_NUMBER_OF_COLUMNS_IN_SELECT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_UPDATE_WITH_READLOCK
    if (!(val = PyLong_FromLong(ER_CANT_UPDATE_WITH_READLOCK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_UPDATE_WITH_READLOCK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_MIXING_NOT_ALLOWED
    if (!(val = PyLong_FromLong(ER_MIXING_NOT_ALLOWED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_MIXING_NOT_ALLOWED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DUP_ARGUMENT
    if (!(val = PyLong_FromLong(ER_DUP_ARGUMENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DUP_ARGUMENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_USER_LIMIT_REACHED
    if (!(val = PyLong_FromLong(ER_USER_LIMIT_REACHED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_USER_LIMIT_REACHED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SPECIFIC_ACCESS_DENIED_ERROR
    if (!(val = PyLong_FromLong(ER_SPECIFIC_ACCESS_DENIED_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SPECIFIC_ACCESS_DENIED_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LOCAL_VARIABLE
    if (!(val = PyLong_FromLong(ER_LOCAL_VARIABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LOCAL_VARIABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_GLOBAL_VARIABLE
    if (!(val = PyLong_FromLong(ER_GLOBAL_VARIABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_GLOBAL_VARIABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_DEFAULT
    if (!(val = PyLong_FromLong(ER_NO_DEFAULT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_DEFAULT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_VALUE_FOR_VAR
    if (!(val = PyLong_FromLong(ER_WRONG_VALUE_FOR_VAR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_VALUE_FOR_VAR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_TYPE_FOR_VAR
    if (!(val = PyLong_FromLong(ER_WRONG_TYPE_FOR_VAR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_TYPE_FOR_VAR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VAR_CANT_BE_READ
    if (!(val = PyLong_FromLong(ER_VAR_CANT_BE_READ)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VAR_CANT_BE_READ", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_USE_OPTION_HERE
    if (!(val = PyLong_FromLong(ER_CANT_USE_OPTION_HERE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_USE_OPTION_HERE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NOT_SUPPORTED_YET
    if (!(val = PyLong_FromLong(ER_NOT_SUPPORTED_YET)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NOT_SUPPORTED_YET", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_MASTER_FATAL_ERROR_READING_BINLOG
    if (!(val = PyLong_FromLong(ER_MASTER_FATAL_ERROR_READING_BINLOG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_MASTER_FATAL_ERROR_READING_BINLOG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_IGNORED_TABLE
    if (!(val = PyLong_FromLong(ER_SLAVE_IGNORED_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_IGNORED_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_INCORRECT_GLOBAL_LOCAL_VAR
    if (!(val = PyLong_FromLong(ER_INCORRECT_GLOBAL_LOCAL_VAR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_INCORRECT_GLOBAL_LOCAL_VAR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_FK_DEF
    if (!(val = PyLong_FromLong(ER_WRONG_FK_DEF)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_FK_DEF", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_KEY_REF_DO_NOT_MATCH_TABLE_REF
    if (!(val = PyLong_FromLong(ER_KEY_REF_DO_NOT_MATCH_TABLE_REF)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_KEY_REF_DO_NOT_MATCH_TABLE_REF", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_OPERAND_COLUMNS
    if (!(val = PyLong_FromLong(ER_OPERAND_COLUMNS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_OPERAND_COLUMNS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SUBQUERY_NO_1_ROW
    if (!(val = PyLong_FromLong(ER_SUBQUERY_NO_1_ROW)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SUBQUERY_NO_1_ROW", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNKNOWN_STMT_HANDLER
    if (!(val = PyLong_FromLong(ER_UNKNOWN_STMT_HANDLER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNKNOWN_STMT_HANDLER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CORRUPT_HELP_DB
    if (!(val = PyLong_FromLong(ER_CORRUPT_HELP_DB)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CORRUPT_HELP_DB", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CYCLIC_REFERENCE
    if (!(val = PyLong_FromLong(ER_CYCLIC_REFERENCE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CYCLIC_REFERENCE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_AUTO_CONVERT
    if (!(val = PyLong_FromLong(ER_AUTO_CONVERT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_AUTO_CONVERT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ILLEGAL_REFERENCE
    if (!(val = PyLong_FromLong(ER_ILLEGAL_REFERENCE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ILLEGAL_REFERENCE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DERIVED_MUST_HAVE_ALIAS
    if (!(val = PyLong_FromLong(ER_DERIVED_MUST_HAVE_ALIAS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DERIVED_MUST_HAVE_ALIAS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SELECT_REDUCED
    if (!(val = PyLong_FromLong(ER_SELECT_REDUCED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SELECT_REDUCED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLENAME_NOT_ALLOWED_HERE
    if (!(val = PyLong_FromLong(ER_TABLENAME_NOT_ALLOWED_HERE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLENAME_NOT_ALLOWED_HERE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NOT_SUPPORTED_AUTH_MODE
    if (!(val = PyLong_FromLong(ER_NOT_SUPPORTED_AUTH_MODE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NOT_SUPPORTED_AUTH_MODE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SPATIAL_CANT_HAVE_NULL
    if (!(val = PyLong_FromLong(ER_SPATIAL_CANT_HAVE_NULL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SPATIAL_CANT_HAVE_NULL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_COLLATION_CHARSET_MISMATCH
    if (!(val = PyLong_FromLong(ER_COLLATION_CHARSET_MISMATCH)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_COLLATION_CHARSET_MISMATCH", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_WAS_RUNNING
    if (!(val = PyLong_FromLong(ER_SLAVE_WAS_RUNNING)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_WAS_RUNNING", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_WAS_NOT_RUNNING
    if (!(val = PyLong_FromLong(ER_SLAVE_WAS_NOT_RUNNING)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_WAS_NOT_RUNNING", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_BIG_FOR_UNCOMPRESS
    if (!(val = PyLong_FromLong(ER_TOO_BIG_FOR_UNCOMPRESS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_BIG_FOR_UNCOMPRESS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ZLIB_Z_MEM_ERROR
    if (!(val = PyLong_FromLong(ER_ZLIB_Z_MEM_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ZLIB_Z_MEM_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ZLIB_Z_BUF_ERROR
    if (!(val = PyLong_FromLong(ER_ZLIB_Z_BUF_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ZLIB_Z_BUF_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ZLIB_Z_DATA_ERROR
    if (!(val = PyLong_FromLong(ER_ZLIB_Z_DATA_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ZLIB_Z_DATA_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CUT_VALUE_GROUP_CONCAT
    if (!(val = PyLong_FromLong(ER_CUT_VALUE_GROUP_CONCAT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CUT_VALUE_GROUP_CONCAT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_TOO_FEW_RECORDS
    if (!(val = PyLong_FromLong(ER_WARN_TOO_FEW_RECORDS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_TOO_FEW_RECORDS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_TOO_MANY_RECORDS
    if (!(val = PyLong_FromLong(ER_WARN_TOO_MANY_RECORDS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_TOO_MANY_RECORDS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_NULL_TO_NOTNULL
    if (!(val = PyLong_FromLong(ER_WARN_NULL_TO_NOTNULL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_NULL_TO_NOTNULL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_DATA_OUT_OF_RANGE
    if (!(val = PyLong_FromLong(ER_WARN_DATA_OUT_OF_RANGE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_DATA_OUT_OF_RANGE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_USING_OTHER_HANDLER
    if (!(val = PyLong_FromLong(ER_WARN_USING_OTHER_HANDLER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_USING_OTHER_HANDLER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_AGGREGATE_2COLLATIONS
    if (!(val = PyLong_FromLong(ER_CANT_AGGREGATE_2COLLATIONS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_AGGREGATE_2COLLATIONS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DROP_USER
    if (!(val = PyLong_FromLong(ER_DROP_USER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DROP_USER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_REVOKE_GRANTS
    if (!(val = PyLong_FromLong(ER_REVOKE_GRANTS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_REVOKE_GRANTS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_AGGREGATE_3COLLATIONS
    if (!(val = PyLong_FromLong(ER_CANT_AGGREGATE_3COLLATIONS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_AGGREGATE_3COLLATIONS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_AGGREGATE_NCOLLATIONS
    if (!(val = PyLong_FromLong(ER_CANT_AGGREGATE_NCOLLATIONS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_AGGREGATE_NCOLLATIONS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VARIABLE_IS_NOT_STRUCT
    if (!(val = PyLong_FromLong(ER_VARIABLE_IS_NOT_STRUCT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VARIABLE_IS_NOT_STRUCT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNKNOWN_COLLATION
    if (!(val = PyLong_FromLong(ER_UNKNOWN_COLLATION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNKNOWN_COLLATION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_IGNORED_SSL_PARAMS
    if (!(val = PyLong_FromLong(ER_SLAVE_IGNORED_SSL_PARAMS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_IGNORED_SSL_PARAMS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SERVER_IS_IN_SECURE_AUTH_MODE
    if (!(val = PyLong_FromLong(ER_SERVER_IS_IN_SECURE_AUTH_MODE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SERVER_IS_IN_SECURE_AUTH_MODE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_FIELD_RESOLVED
    if (!(val = PyLong_FromLong(ER_WARN_FIELD_RESOLVED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_FIELD_RESOLVED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BAD_SLAVE_UNTIL_COND
    if (!(val = PyLong_FromLong(ER_BAD_SLAVE_UNTIL_COND)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BAD_SLAVE_UNTIL_COND", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_MISSING_SKIP_SLAVE
    if (!(val = PyLong_FromLong(ER_MISSING_SKIP_SLAVE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_MISSING_SKIP_SLAVE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNTIL_COND_IGNORED
    if (!(val = PyLong_FromLong(ER_UNTIL_COND_IGNORED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNTIL_COND_IGNORED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_NAME_FOR_INDEX
    if (!(val = PyLong_FromLong(ER_WRONG_NAME_FOR_INDEX)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_NAME_FOR_INDEX", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_NAME_FOR_CATALOG
    if (!(val = PyLong_FromLong(ER_WRONG_NAME_FOR_CATALOG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_NAME_FOR_CATALOG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_QC_RESIZE
    if (!(val = PyLong_FromLong(ER_WARN_QC_RESIZE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_QC_RESIZE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BAD_FT_COLUMN
    if (!(val = PyLong_FromLong(ER_BAD_FT_COLUMN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BAD_FT_COLUMN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNKNOWN_KEY_CACHE
    if (!(val = PyLong_FromLong(ER_UNKNOWN_KEY_CACHE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNKNOWN_KEY_CACHE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_HOSTNAME_WONT_WORK
    if (!(val = PyLong_FromLong(ER_WARN_HOSTNAME_WONT_WORK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_HOSTNAME_WONT_WORK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNKNOWN_STORAGE_ENGINE
    if (!(val = PyLong_FromLong(ER_UNKNOWN_STORAGE_ENGINE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNKNOWN_STORAGE_ENGINE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_DEPRECATED_SYNTAX
    if (!(val = PyLong_FromLong(ER_WARN_DEPRECATED_SYNTAX)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_DEPRECATED_SYNTAX", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NON_UPDATABLE_TABLE
    if (!(val = PyLong_FromLong(ER_NON_UPDATABLE_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NON_UPDATABLE_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FEATURE_DISABLED
    if (!(val = PyLong_FromLong(ER_FEATURE_DISABLED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FEATURE_DISABLED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_OPTION_PREVENTS_STATEMENT
    if (!(val = PyLong_FromLong(ER_OPTION_PREVENTS_STATEMENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_OPTION_PREVENTS_STATEMENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DUPLICATED_VALUE_IN_TYPE
    if (!(val = PyLong_FromLong(ER_DUPLICATED_VALUE_IN_TYPE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DUPLICATED_VALUE_IN_TYPE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRUNCATED_WRONG_VALUE
    if (!(val = PyLong_FromLong(ER_TRUNCATED_WRONG_VALUE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRUNCATED_WRONG_VALUE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_MUCH_AUTO_TIMESTAMP_COLS
    if (!(val = PyLong_FromLong(ER_TOO_MUCH_AUTO_TIMESTAMP_COLS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_MUCH_AUTO_TIMESTAMP_COLS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_INVALID_ON_UPDATE
    if (!(val = PyLong_FromLong(ER_INVALID_ON_UPDATE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_INVALID_ON_UPDATE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNSUPPORTED_PS
    if (!(val = PyLong_FromLong(ER_UNSUPPORTED_PS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNSUPPORTED_PS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_GET_ERRMSG
    if (!(val = PyLong_FromLong(ER_GET_ERRMSG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_GET_ERRMSG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_GET_TEMPORARY_ERRMSG
    if (!(val = PyLong_FromLong(ER_GET_TEMPORARY_ERRMSG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_GET_TEMPORARY_ERRMSG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNKNOWN_TIME_ZONE
    if (!(val = PyLong_FromLong(ER_UNKNOWN_TIME_ZONE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNKNOWN_TIME_ZONE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_INVALID_TIMESTAMP
    if (!(val = PyLong_FromLong(ER_WARN_INVALID_TIMESTAMP)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_INVALID_TIMESTAMP", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_INVALID_CHARACTER_STRING
    if (!(val = PyLong_FromLong(ER_INVALID_CHARACTER_STRING)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_INVALID_CHARACTER_STRING", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_ALLOWED_PACKET_OVERFLOWED
    if (!(val = PyLong_FromLong(ER_WARN_ALLOWED_PACKET_OVERFLOWED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_ALLOWED_PACKET_OVERFLOWED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CONFLICTING_DECLARATIONS
    if (!(val = PyLong_FromLong(ER_CONFLICTING_DECLARATIONS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CONFLICTING_DECLARATIONS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_NO_RECURSIVE_CREATE
    if (!(val = PyLong_FromLong(ER_SP_NO_RECURSIVE_CREATE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_NO_RECURSIVE_CREATE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_ALREADY_EXISTS
    if (!(val = PyLong_FromLong(ER_SP_ALREADY_EXISTS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_ALREADY_EXISTS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_DOES_NOT_EXIST
    if (!(val = PyLong_FromLong(ER_SP_DOES_NOT_EXIST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_DOES_NOT_EXIST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_DROP_FAILED
    if (!(val = PyLong_FromLong(ER_SP_DROP_FAILED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_DROP_FAILED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_STORE_FAILED
    if (!(val = PyLong_FromLong(ER_SP_STORE_FAILED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_STORE_FAILED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_LILABEL_MISMATCH
    if (!(val = PyLong_FromLong(ER_SP_LILABEL_MISMATCH)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_LILABEL_MISMATCH", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_LABEL_REDEFINE
    if (!(val = PyLong_FromLong(ER_SP_LABEL_REDEFINE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_LABEL_REDEFINE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_LABEL_MISMATCH
    if (!(val = PyLong_FromLong(ER_SP_LABEL_MISMATCH)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_LABEL_MISMATCH", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_UNINIT_VAR
    if (!(val = PyLong_FromLong(ER_SP_UNINIT_VAR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_UNINIT_VAR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_BADSELECT
    if (!(val = PyLong_FromLong(ER_SP_BADSELECT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_BADSELECT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_BADRETURN
    if (!(val = PyLong_FromLong(ER_SP_BADRETURN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_BADRETURN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_BADSTATEMENT
    if (!(val = PyLong_FromLong(ER_SP_BADSTATEMENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_BADSTATEMENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UPDATE_LOG_DEPRECATED_IGNORED
    if (!(val = PyLong_FromLong(ER_UPDATE_LOG_DEPRECATED_IGNORED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UPDATE_LOG_DEPRECATED_IGNORED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UPDATE_LOG_DEPRECATED_TRANSLATED
    if (!(val = PyLong_FromLong(ER_UPDATE_LOG_DEPRECATED_TRANSLATED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UPDATE_LOG_DEPRECATED_TRANSLATED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_QUERY_INTERRUPTED
    if (!(val = PyLong_FromLong(ER_QUERY_INTERRUPTED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_QUERY_INTERRUPTED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_WRONG_NO_OF_ARGS
    if (!(val = PyLong_FromLong(ER_SP_WRONG_NO_OF_ARGS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_WRONG_NO_OF_ARGS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_COND_MISMATCH
    if (!(val = PyLong_FromLong(ER_SP_COND_MISMATCH)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_COND_MISMATCH", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_NORETURN
    if (!(val = PyLong_FromLong(ER_SP_NORETURN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_NORETURN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_NORETURNEND
    if (!(val = PyLong_FromLong(ER_SP_NORETURNEND)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_NORETURNEND", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_BAD_CURSOR_QUERY
    if (!(val = PyLong_FromLong(ER_SP_BAD_CURSOR_QUERY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_BAD_CURSOR_QUERY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_BAD_CURSOR_SELECT
    if (!(val = PyLong_FromLong(ER_SP_BAD_CURSOR_SELECT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_BAD_CURSOR_SELECT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_CURSOR_MISMATCH
    if (!(val = PyLong_FromLong(ER_SP_CURSOR_MISMATCH)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_CURSOR_MISMATCH", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_CURSOR_ALREADY_OPEN
    if (!(val = PyLong_FromLong(ER_SP_CURSOR_ALREADY_OPEN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_CURSOR_ALREADY_OPEN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_CURSOR_NOT_OPEN
    if (!(val = PyLong_FromLong(ER_SP_CURSOR_NOT_OPEN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_CURSOR_NOT_OPEN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_UNDECLARED_VAR
    if (!(val = PyLong_FromLong(ER_SP_UNDECLARED_VAR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_UNDECLARED_VAR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_WRONG_NO_OF_FETCH_ARGS
    if (!(val = PyLong_FromLong(ER_SP_WRONG_NO_OF_FETCH_ARGS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_WRONG_NO_OF_FETCH_ARGS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_FETCH_NO_DATA
    if (!(val = PyLong_FromLong(ER_SP_FETCH_NO_DATA)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_FETCH_NO_DATA", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_DUP_PARAM
    if (!(val = PyLong_FromLong(ER_SP_DUP_PARAM)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_DUP_PARAM", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_DUP_VAR
    if (!(val = PyLong_FromLong(ER_SP_DUP_VAR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_DUP_VAR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_DUP_COND
    if (!(val = PyLong_FromLong(ER_SP_DUP_COND)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_DUP_COND", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_DUP_CURS
    if (!(val = PyLong_FromLong(ER_SP_DUP_CURS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_DUP_CURS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_CANT_ALTER
    if (!(val = PyLong_FromLong(ER_SP_CANT_ALTER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_CANT_ALTER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_SUBSELECT_NYI
    if (!(val = PyLong_FromLong(ER_SP_SUBSELECT_NYI)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_SUBSELECT_NYI", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_STMT_NOT_ALLOWED_IN_SF_OR_TRG
    if (!(val = PyLong_FromLong(ER_STMT_NOT_ALLOWED_IN_SF_OR_TRG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_STMT_NOT_ALLOWED_IN_SF_OR_TRG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_VARCOND_AFTER_CURSHNDLR
    if (!(val = PyLong_FromLong(ER_SP_VARCOND_AFTER_CURSHNDLR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_VARCOND_AFTER_CURSHNDLR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_CURSOR_AFTER_HANDLER
    if (!(val = PyLong_FromLong(ER_SP_CURSOR_AFTER_HANDLER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_CURSOR_AFTER_HANDLER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_CASE_NOT_FOUND
    if (!(val = PyLong_FromLong(ER_SP_CASE_NOT_FOUND)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_CASE_NOT_FOUND", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FPARSER_TOO_BIG_FILE
    if (!(val = PyLong_FromLong(ER_FPARSER_TOO_BIG_FILE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FPARSER_TOO_BIG_FILE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FPARSER_BAD_HEADER
    if (!(val = PyLong_FromLong(ER_FPARSER_BAD_HEADER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FPARSER_BAD_HEADER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FPARSER_EOF_IN_COMMENT
    if (!(val = PyLong_FromLong(ER_FPARSER_EOF_IN_COMMENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FPARSER_EOF_IN_COMMENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FPARSER_ERROR_IN_PARAMETER
    if (!(val = PyLong_FromLong(ER_FPARSER_ERROR_IN_PARAMETER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FPARSER_ERROR_IN_PARAMETER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FPARSER_EOF_IN_UNKNOWN_PARAMETER
    if (!(val = PyLong_FromLong(ER_FPARSER_EOF_IN_UNKNOWN_PARAMETER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FPARSER_EOF_IN_UNKNOWN_PARAMETER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_NO_EXPLAIN
    if (!(val = PyLong_FromLong(ER_VIEW_NO_EXPLAIN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_NO_EXPLAIN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FRM_UNKNOWN_TYPE
    if (!(val = PyLong_FromLong(ER_FRM_UNKNOWN_TYPE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FRM_UNKNOWN_TYPE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_OBJECT
    if (!(val = PyLong_FromLong(ER_WRONG_OBJECT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_OBJECT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NONUPDATEABLE_COLUMN
    if (!(val = PyLong_FromLong(ER_NONUPDATEABLE_COLUMN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NONUPDATEABLE_COLUMN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_SELECT_DERIVED
    if (!(val = PyLong_FromLong(ER_VIEW_SELECT_DERIVED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_SELECT_DERIVED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_SELECT_CLAUSE
    if (!(val = PyLong_FromLong(ER_VIEW_SELECT_CLAUSE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_SELECT_CLAUSE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_SELECT_VARIABLE
    if (!(val = PyLong_FromLong(ER_VIEW_SELECT_VARIABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_SELECT_VARIABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_SELECT_TMPTABLE
    if (!(val = PyLong_FromLong(ER_VIEW_SELECT_TMPTABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_SELECT_TMPTABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_WRONG_LIST
    if (!(val = PyLong_FromLong(ER_VIEW_WRONG_LIST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_WRONG_LIST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_VIEW_MERGE
    if (!(val = PyLong_FromLong(ER_WARN_VIEW_MERGE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_VIEW_MERGE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_VIEW_WITHOUT_KEY
    if (!(val = PyLong_FromLong(ER_WARN_VIEW_WITHOUT_KEY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_VIEW_WITHOUT_KEY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_INVALID
    if (!(val = PyLong_FromLong(ER_VIEW_INVALID)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_INVALID", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_NO_DROP_SP
    if (!(val = PyLong_FromLong(ER_SP_NO_DROP_SP)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_NO_DROP_SP", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_GOTO_IN_HNDLR
    if (!(val = PyLong_FromLong(ER_SP_GOTO_IN_HNDLR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_GOTO_IN_HNDLR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRG_ALREADY_EXISTS
    if (!(val = PyLong_FromLong(ER_TRG_ALREADY_EXISTS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRG_ALREADY_EXISTS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRG_DOES_NOT_EXIST
    if (!(val = PyLong_FromLong(ER_TRG_DOES_NOT_EXIST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRG_DOES_NOT_EXIST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRG_ON_VIEW_OR_TEMP_TABLE
    if (!(val = PyLong_FromLong(ER_TRG_ON_VIEW_OR_TEMP_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRG_ON_VIEW_OR_TEMP_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRG_CANT_CHANGE_ROW
    if (!(val = PyLong_FromLong(ER_TRG_CANT_CHANGE_ROW)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRG_CANT_CHANGE_ROW", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRG_NO_SUCH_ROW_IN_TRG
    if (!(val = PyLong_FromLong(ER_TRG_NO_SUCH_ROW_IN_TRG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRG_NO_SUCH_ROW_IN_TRG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_DEFAULT_FOR_FIELD
    if (!(val = PyLong_FromLong(ER_NO_DEFAULT_FOR_FIELD)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_DEFAULT_FOR_FIELD", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DIVISION_BY_ZERO
    if (!(val = PyLong_FromLong(ER_DIVISION_BY_ZERO)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DIVISION_BY_ZERO", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRUNCATED_WRONG_VALUE_FOR_FIELD
    if (!(val = PyLong_FromLong(ER_TRUNCATED_WRONG_VALUE_FOR_FIELD)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRUNCATED_WRONG_VALUE_FOR_FIELD", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ILLEGAL_VALUE_FOR_TYPE
    if (!(val = PyLong_FromLong(ER_ILLEGAL_VALUE_FOR_TYPE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ILLEGAL_VALUE_FOR_TYPE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_NONUPD_CHECK
    if (!(val = PyLong_FromLong(ER_VIEW_NONUPD_CHECK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_NONUPD_CHECK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_CHECK_FAILED
    if (!(val = PyLong_FromLong(ER_VIEW_CHECK_FAILED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_CHECK_FAILED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PROCACCESS_DENIED_ERROR
    if (!(val = PyLong_FromLong(ER_PROCACCESS_DENIED_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PROCACCESS_DENIED_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_RELAY_LOG_FAIL
    if (!(val = PyLong_FromLong(ER_RELAY_LOG_FAIL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_RELAY_LOG_FAIL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PASSWD_LENGTH
    if (!(val = PyLong_FromLong(ER_PASSWD_LENGTH)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PASSWD_LENGTH", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNKNOWN_TARGET_BINLOG
    if (!(val = PyLong_FromLong(ER_UNKNOWN_TARGET_BINLOG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNKNOWN_TARGET_BINLOG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_IO_ERR_LOG_INDEX_READ
    if (!(val = PyLong_FromLong(ER_IO_ERR_LOG_INDEX_READ)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_IO_ERR_LOG_INDEX_READ", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BINLOG_PURGE_PROHIBITED
    if (!(val = PyLong_FromLong(ER_BINLOG_PURGE_PROHIBITED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BINLOG_PURGE_PROHIBITED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FSEEK_FAIL
    if (!(val = PyLong_FromLong(ER_FSEEK_FAIL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FSEEK_FAIL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BINLOG_PURGE_FATAL_ERR
    if (!(val = PyLong_FromLong(ER_BINLOG_PURGE_FATAL_ERR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BINLOG_PURGE_FATAL_ERR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LOG_IN_USE
    if (!(val = PyLong_FromLong(ER_LOG_IN_USE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LOG_IN_USE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LOG_PURGE_UNKNOWN_ERR
    if (!(val = PyLong_FromLong(ER_LOG_PURGE_UNKNOWN_ERR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LOG_PURGE_UNKNOWN_ERR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_RELAY_LOG_INIT
    if (!(val = PyLong_FromLong(ER_RELAY_LOG_INIT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_RELAY_LOG_INIT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_BINARY_LOGGING
    if (!(val = PyLong_FromLong(ER_NO_BINARY_LOGGING)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_BINARY_LOGGING", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_RESERVED_SYNTAX
    if (!(val = PyLong_FromLong(ER_RESERVED_SYNTAX)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_RESERVED_SYNTAX", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WSAS_FAILED
    if (!(val = PyLong_FromLong(ER_WSAS_FAILED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WSAS_FAILED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DIFF_GROUPS_PROC
    if (!(val = PyLong_FromLong(ER_DIFF_GROUPS_PROC)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DIFF_GROUPS_PROC", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_GROUP_FOR_PROC
    if (!(val = PyLong_FromLong(ER_NO_GROUP_FOR_PROC)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_GROUP_FOR_PROC", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ORDER_WITH_PROC
    if (!(val = PyLong_FromLong(ER_ORDER_WITH_PROC)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ORDER_WITH_PROC", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LOGGING_PROHIBIT_CHANGING_OF
    if (!(val = PyLong_FromLong(ER_LOGGING_PROHIBIT_CHANGING_OF)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LOGGING_PROHIBIT_CHANGING_OF", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_FILE_MAPPING
    if (!(val = PyLong_FromLong(ER_NO_FILE_MAPPING)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_FILE_MAPPING", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_MAGIC
    if (!(val = PyLong_FromLong(ER_WRONG_MAGIC)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_MAGIC", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PS_MANY_PARAM
    if (!(val = PyLong_FromLong(ER_PS_MANY_PARAM)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PS_MANY_PARAM", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_KEY_PART_0
    if (!(val = PyLong_FromLong(ER_KEY_PART_0)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_KEY_PART_0", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_CHECKSUM
    if (!(val = PyLong_FromLong(ER_VIEW_CHECKSUM)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_CHECKSUM", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_MULTIUPDATE
    if (!(val = PyLong_FromLong(ER_VIEW_MULTIUPDATE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_MULTIUPDATE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_NO_INSERT_FIELD_LIST
    if (!(val = PyLong_FromLong(ER_VIEW_NO_INSERT_FIELD_LIST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_NO_INSERT_FIELD_LIST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_DELETE_MERGE_VIEW
    if (!(val = PyLong_FromLong(ER_VIEW_DELETE_MERGE_VIEW)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_DELETE_MERGE_VIEW", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANNOT_USER
    if (!(val = PyLong_FromLong(ER_CANNOT_USER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANNOT_USER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_XAER_NOTA
    if (!(val = PyLong_FromLong(ER_XAER_NOTA)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_XAER_NOTA", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_XAER_INVAL
    if (!(val = PyLong_FromLong(ER_XAER_INVAL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_XAER_INVAL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_XAER_RMFAIL
    if (!(val = PyLong_FromLong(ER_XAER_RMFAIL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_XAER_RMFAIL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_XAER_OUTSIDE
    if (!(val = PyLong_FromLong(ER_XAER_OUTSIDE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_XAER_OUTSIDE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_XAER_RMERR
    if (!(val = PyLong_FromLong(ER_XAER_RMERR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_XAER_RMERR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_XA_RBROLLBACK
    if (!(val = PyLong_FromLong(ER_XA_RBROLLBACK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_XA_RBROLLBACK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NONEXISTING_PROC_GRANT
    if (!(val = PyLong_FromLong(ER_NONEXISTING_PROC_GRANT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NONEXISTING_PROC_GRANT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PROC_AUTO_GRANT_FAIL
    if (!(val = PyLong_FromLong(ER_PROC_AUTO_GRANT_FAIL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PROC_AUTO_GRANT_FAIL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PROC_AUTO_REVOKE_FAIL
    if (!(val = PyLong_FromLong(ER_PROC_AUTO_REVOKE_FAIL)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PROC_AUTO_REVOKE_FAIL", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DATA_TOO_LONG
    if (!(val = PyLong_FromLong(ER_DATA_TOO_LONG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DATA_TOO_LONG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_BAD_SQLSTATE
    if (!(val = PyLong_FromLong(ER_SP_BAD_SQLSTATE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_BAD_SQLSTATE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_STARTUP
    if (!(val = PyLong_FromLong(ER_STARTUP)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_STARTUP", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LOAD_FROM_FIXED_SIZE_ROWS_TO_VAR
    if (!(val = PyLong_FromLong(ER_LOAD_FROM_FIXED_SIZE_ROWS_TO_VAR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LOAD_FROM_FIXED_SIZE_ROWS_TO_VAR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_CREATE_USER_WITH_GRANT
    if (!(val = PyLong_FromLong(ER_CANT_CREATE_USER_WITH_GRANT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_CREATE_USER_WITH_GRANT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_VALUE_FOR_TYPE
    if (!(val = PyLong_FromLong(ER_WRONG_VALUE_FOR_TYPE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_VALUE_FOR_TYPE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLE_DEF_CHANGED
    if (!(val = PyLong_FromLong(ER_TABLE_DEF_CHANGED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLE_DEF_CHANGED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_DUP_HANDLER
    if (!(val = PyLong_FromLong(ER_SP_DUP_HANDLER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_DUP_HANDLER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_NOT_VAR_ARG
    if (!(val = PyLong_FromLong(ER_SP_NOT_VAR_ARG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_NOT_VAR_ARG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_NO_RETSET
    if (!(val = PyLong_FromLong(ER_SP_NO_RETSET)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_NO_RETSET", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_CREATE_GEOMETRY_OBJECT
    if (!(val = PyLong_FromLong(ER_CANT_CREATE_GEOMETRY_OBJECT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_CREATE_GEOMETRY_OBJECT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FAILED_ROUTINE_BREAK_BINLOG
    if (!(val = PyLong_FromLong(ER_FAILED_ROUTINE_BREAK_BINLOG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FAILED_ROUTINE_BREAK_BINLOG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BINLOG_UNSAFE_ROUTINE
    if (!(val = PyLong_FromLong(ER_BINLOG_UNSAFE_ROUTINE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BINLOG_UNSAFE_ROUTINE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BINLOG_CREATE_ROUTINE_NEED_SUPER
    if (!(val = PyLong_FromLong(ER_BINLOG_CREATE_ROUTINE_NEED_SUPER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BINLOG_CREATE_ROUTINE_NEED_SUPER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EXEC_STMT_WITH_OPEN_CURSOR
    if (!(val = PyLong_FromLong(ER_EXEC_STMT_WITH_OPEN_CURSOR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EXEC_STMT_WITH_OPEN_CURSOR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_STMT_HAS_NO_OPEN_CURSOR
    if (!(val = PyLong_FromLong(ER_STMT_HAS_NO_OPEN_CURSOR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_STMT_HAS_NO_OPEN_CURSOR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_COMMIT_NOT_ALLOWED_IN_SF_OR_TRG
    if (!(val = PyLong_FromLong(ER_COMMIT_NOT_ALLOWED_IN_SF_OR_TRG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_COMMIT_NOT_ALLOWED_IN_SF_OR_TRG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_DEFAULT_FOR_VIEW_FIELD
    if (!(val = PyLong_FromLong(ER_NO_DEFAULT_FOR_VIEW_FIELD)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_DEFAULT_FOR_VIEW_FIELD", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_NO_RECURSION
    if (!(val = PyLong_FromLong(ER_SP_NO_RECURSION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_NO_RECURSION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_BIG_SCALE
    if (!(val = PyLong_FromLong(ER_TOO_BIG_SCALE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_BIG_SCALE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_BIG_PRECISION
    if (!(val = PyLong_FromLong(ER_TOO_BIG_PRECISION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_BIG_PRECISION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_M_BIGGER_THAN_D
    if (!(val = PyLong_FromLong(ER_M_BIGGER_THAN_D)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_M_BIGGER_THAN_D", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_LOCK_OF_SYSTEM_TABLE
    if (!(val = PyLong_FromLong(ER_WRONG_LOCK_OF_SYSTEM_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_LOCK_OF_SYSTEM_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CONNECT_TO_FOREIGN_DATA_SOURCE
    if (!(val = PyLong_FromLong(ER_CONNECT_TO_FOREIGN_DATA_SOURCE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CONNECT_TO_FOREIGN_DATA_SOURCE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_QUERY_ON_FOREIGN_DATA_SOURCE
    if (!(val = PyLong_FromLong(ER_QUERY_ON_FOREIGN_DATA_SOURCE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_QUERY_ON_FOREIGN_DATA_SOURCE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FOREIGN_DATA_SOURCE_DOESNT_EXIST
    if (!(val = PyLong_FromLong(ER_FOREIGN_DATA_SOURCE_DOESNT_EXIST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FOREIGN_DATA_SOURCE_DOESNT_EXIST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FOREIGN_DATA_STRING_INVALID_CANT_CREATE
    if (!(val = PyLong_FromLong(ER_FOREIGN_DATA_STRING_INVALID_CANT_CREATE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FOREIGN_DATA_STRING_INVALID_CANT_CREATE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FOREIGN_DATA_STRING_INVALID
    if (!(val = PyLong_FromLong(ER_FOREIGN_DATA_STRING_INVALID)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FOREIGN_DATA_STRING_INVALID", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_CREATE_FEDERATED_TABLE
    if (!(val = PyLong_FromLong(ER_CANT_CREATE_FEDERATED_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_CREATE_FEDERATED_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRG_IN_WRONG_SCHEMA
    if (!(val = PyLong_FromLong(ER_TRG_IN_WRONG_SCHEMA)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRG_IN_WRONG_SCHEMA", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_STACK_OVERRUN_NEED_MORE
    if (!(val = PyLong_FromLong(ER_STACK_OVERRUN_NEED_MORE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_STACK_OVERRUN_NEED_MORE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_LONG_BODY
    if (!(val = PyLong_FromLong(ER_TOO_LONG_BODY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_LONG_BODY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_CANT_DROP_DEFAULT_KEYCACHE
    if (!(val = PyLong_FromLong(ER_WARN_CANT_DROP_DEFAULT_KEYCACHE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_CANT_DROP_DEFAULT_KEYCACHE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_BIG_DISPLAYWIDTH
    if (!(val = PyLong_FromLong(ER_TOO_BIG_DISPLAYWIDTH)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_BIG_DISPLAYWIDTH", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_XAER_DUPID
    if (!(val = PyLong_FromLong(ER_XAER_DUPID)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_XAER_DUPID", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DATETIME_FUNCTION_OVERFLOW
    if (!(val = PyLong_FromLong(ER_DATETIME_FUNCTION_OVERFLOW)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DATETIME_FUNCTION_OVERFLOW", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_UPDATE_USED_TABLE_IN_SF_OR_TRG
    if (!(val = PyLong_FromLong(ER_CANT_UPDATE_USED_TABLE_IN_SF_OR_TRG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_UPDATE_USED_TABLE_IN_SF_OR_TRG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_PREVENT_UPDATE
    if (!(val = PyLong_FromLong(ER_VIEW_PREVENT_UPDATE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_PREVENT_UPDATE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PS_NO_RECURSION
    if (!(val = PyLong_FromLong(ER_PS_NO_RECURSION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PS_NO_RECURSION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_CANT_SET_AUTOCOMMIT
    if (!(val = PyLong_FromLong(ER_SP_CANT_SET_AUTOCOMMIT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_CANT_SET_AUTOCOMMIT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_MALFORMED_DEFINER
    if (!(val = PyLong_FromLong(ER_MALFORMED_DEFINER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_MALFORMED_DEFINER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_FRM_NO_USER
    if (!(val = PyLong_FromLong(ER_VIEW_FRM_NO_USER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_FRM_NO_USER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_OTHER_USER
    if (!(val = PyLong_FromLong(ER_VIEW_OTHER_USER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_OTHER_USER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_SUCH_USER
    if (!(val = PyLong_FromLong(ER_NO_SUCH_USER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_SUCH_USER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FORBID_SCHEMA_CHANGE
    if (!(val = PyLong_FromLong(ER_FORBID_SCHEMA_CHANGE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FORBID_SCHEMA_CHANGE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ROW_IS_REFERENCED_2
    if (!(val = PyLong_FromLong(ER_ROW_IS_REFERENCED_2)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ROW_IS_REFERENCED_2", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_REFERENCED_ROW_2
    if (!(val = PyLong_FromLong(ER_NO_REFERENCED_ROW_2)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_REFERENCED_ROW_2", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_BAD_VAR_SHADOW
    if (!(val = PyLong_FromLong(ER_SP_BAD_VAR_SHADOW)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_BAD_VAR_SHADOW", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRG_NO_DEFINER
    if (!(val = PyLong_FromLong(ER_TRG_NO_DEFINER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRG_NO_DEFINER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_OLD_FILE_FORMAT
    if (!(val = PyLong_FromLong(ER_OLD_FILE_FORMAT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_OLD_FILE_FORMAT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_RECURSION_LIMIT
    if (!(val = PyLong_FromLong(ER_SP_RECURSION_LIMIT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_RECURSION_LIMIT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_PROC_TABLE_CORRUPT
    if (!(val = PyLong_FromLong(ER_SP_PROC_TABLE_CORRUPT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_PROC_TABLE_CORRUPT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_WRONG_NAME
    if (!(val = PyLong_FromLong(ER_SP_WRONG_NAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_WRONG_NAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLE_NEEDS_UPGRADE
    if (!(val = PyLong_FromLong(ER_TABLE_NEEDS_UPGRADE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLE_NEEDS_UPGRADE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SP_NO_AGGREGATE
    if (!(val = PyLong_FromLong(ER_SP_NO_AGGREGATE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SP_NO_AGGREGATE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_MAX_PREPARED_STMT_COUNT_REACHED
    if (!(val = PyLong_FromLong(ER_MAX_PREPARED_STMT_COUNT_REACHED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_MAX_PREPARED_STMT_COUNT_REACHED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_RECURSIVE
    if (!(val = PyLong_FromLong(ER_VIEW_RECURSIVE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_RECURSIVE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NON_GROUPING_FIELD_USED
    if (!(val = PyLong_FromLong(ER_NON_GROUPING_FIELD_USED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NON_GROUPING_FIELD_USED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLE_CANT_HANDLE_SPKEYS
    if (!(val = PyLong_FromLong(ER_TABLE_CANT_HANDLE_SPKEYS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLE_CANT_HANDLE_SPKEYS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_TRIGGERS_ON_SYSTEM_SCHEMA
    if (!(val = PyLong_FromLong(ER_NO_TRIGGERS_ON_SYSTEM_SCHEMA)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_TRIGGERS_ON_SYSTEM_SCHEMA", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_REMOVED_SPACES
    if (!(val = PyLong_FromLong(ER_REMOVED_SPACES)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_REMOVED_SPACES", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_AUTOINC_READ_FAILED
    if (!(val = PyLong_FromLong(ER_AUTOINC_READ_FAILED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_AUTOINC_READ_FAILED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_USERNAME
    if (!(val = PyLong_FromLong(ER_USERNAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_USERNAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_HOSTNAME
    if (!(val = PyLong_FromLong(ER_HOSTNAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_HOSTNAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_STRING_LENGTH
    if (!(val = PyLong_FromLong(ER_WRONG_STRING_LENGTH)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_STRING_LENGTH", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NON_INSERTABLE_TABLE
    if (!(val = PyLong_FromLong(ER_NON_INSERTABLE_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NON_INSERTABLE_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ADMIN_WRONG_MRG_TABLE
    if (!(val = PyLong_FromLong(ER_ADMIN_WRONG_MRG_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ADMIN_WRONG_MRG_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_HIGH_LEVEL_OF_NESTING_FOR_SELECT
    if (!(val = PyLong_FromLong(ER_TOO_HIGH_LEVEL_OF_NESTING_FOR_SELECT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_HIGH_LEVEL_OF_NESTING_FOR_SELECT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NAME_BECOMES_EMPTY
    if (!(val = PyLong_FromLong(ER_NAME_BECOMES_EMPTY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NAME_BECOMES_EMPTY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_AMBIGUOUS_FIELD_TERM
    if (!(val = PyLong_FromLong(ER_AMBIGUOUS_FIELD_TERM)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_AMBIGUOUS_FIELD_TERM", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FOREIGN_SERVER_EXISTS
    if (!(val = PyLong_FromLong(ER_FOREIGN_SERVER_EXISTS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FOREIGN_SERVER_EXISTS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FOREIGN_SERVER_DOESNT_EXIST
    if (!(val = PyLong_FromLong(ER_FOREIGN_SERVER_DOESNT_EXIST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FOREIGN_SERVER_DOESNT_EXIST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ILLEGAL_HA_CREATE_OPTION
    if (!(val = PyLong_FromLong(ER_ILLEGAL_HA_CREATE_OPTION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ILLEGAL_HA_CREATE_OPTION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_REQUIRES_VALUES_ERROR
    if (!(val = PyLong_FromLong(ER_PARTITION_REQUIRES_VALUES_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_REQUIRES_VALUES_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_WRONG_VALUES_ERROR
    if (!(val = PyLong_FromLong(ER_PARTITION_WRONG_VALUES_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_WRONG_VALUES_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_MAXVALUE_ERROR
    if (!(val = PyLong_FromLong(ER_PARTITION_MAXVALUE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_MAXVALUE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_SUBPARTITION_ERROR
    if (!(val = PyLong_FromLong(ER_PARTITION_SUBPARTITION_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_SUBPARTITION_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_SUBPART_MIX_ERROR
    if (!(val = PyLong_FromLong(ER_PARTITION_SUBPART_MIX_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_SUBPART_MIX_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_WRONG_NO_PART_ERROR
    if (!(val = PyLong_FromLong(ER_PARTITION_WRONG_NO_PART_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_WRONG_NO_PART_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_WRONG_NO_SUBPART_ERROR
    if (!(val = PyLong_FromLong(ER_PARTITION_WRONG_NO_SUBPART_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_WRONG_NO_SUBPART_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CONST_EXPR_IN_PARTITION_FUNC_ERROR
    if (!(val = PyLong_FromLong(ER_CONST_EXPR_IN_PARTITION_FUNC_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CONST_EXPR_IN_PARTITION_FUNC_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_CONST_EXPR_IN_RANGE_OR_LIST_ERROR
    if (!(val = PyLong_FromLong(ER_NO_CONST_EXPR_IN_RANGE_OR_LIST_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_CONST_EXPR_IN_RANGE_OR_LIST_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FIELD_NOT_FOUND_PART_ERROR
    if (!(val = PyLong_FromLong(ER_FIELD_NOT_FOUND_PART_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FIELD_NOT_FOUND_PART_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LIST_OF_FIELDS_ONLY_IN_HASH_ERROR
    if (!(val = PyLong_FromLong(ER_LIST_OF_FIELDS_ONLY_IN_HASH_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LIST_OF_FIELDS_ONLY_IN_HASH_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_INCONSISTENT_PARTITION_INFO_ERROR
    if (!(val = PyLong_FromLong(ER_INCONSISTENT_PARTITION_INFO_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_INCONSISTENT_PARTITION_INFO_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_FUNC_NOT_ALLOWED_ERROR
    if (!(val = PyLong_FromLong(ER_PARTITION_FUNC_NOT_ALLOWED_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_FUNC_NOT_ALLOWED_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITIONS_MUST_BE_DEFINED_ERROR
    if (!(val = PyLong_FromLong(ER_PARTITIONS_MUST_BE_DEFINED_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITIONS_MUST_BE_DEFINED_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_RANGE_NOT_INCREASING_ERROR
    if (!(val = PyLong_FromLong(ER_RANGE_NOT_INCREASING_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_RANGE_NOT_INCREASING_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_INCONSISTENT_TYPE_OF_FUNCTIONS_ERROR
    if (!(val = PyLong_FromLong(ER_INCONSISTENT_TYPE_OF_FUNCTIONS_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_INCONSISTENT_TYPE_OF_FUNCTIONS_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_MULTIPLE_DEF_CONST_IN_LIST_PART_ERROR
    if (!(val = PyLong_FromLong(ER_MULTIPLE_DEF_CONST_IN_LIST_PART_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_MULTIPLE_DEF_CONST_IN_LIST_PART_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_ENTRY_ERROR
    if (!(val = PyLong_FromLong(ER_PARTITION_ENTRY_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_ENTRY_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_MIX_HANDLER_ERROR
    if (!(val = PyLong_FromLong(ER_MIX_HANDLER_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_MIX_HANDLER_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_NOT_DEFINED_ERROR
    if (!(val = PyLong_FromLong(ER_PARTITION_NOT_DEFINED_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_NOT_DEFINED_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_MANY_PARTITIONS_ERROR
    if (!(val = PyLong_FromLong(ER_TOO_MANY_PARTITIONS_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_MANY_PARTITIONS_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SUBPARTITION_ERROR
    if (!(val = PyLong_FromLong(ER_SUBPARTITION_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SUBPARTITION_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_CREATE_HANDLER_FILE
    if (!(val = PyLong_FromLong(ER_CANT_CREATE_HANDLER_FILE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_CREATE_HANDLER_FILE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BLOB_FIELD_IN_PART_FUNC_ERROR
    if (!(val = PyLong_FromLong(ER_BLOB_FIELD_IN_PART_FUNC_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BLOB_FIELD_IN_PART_FUNC_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNIQUE_KEY_NEED_ALL_FIELDS_IN_PF
    if (!(val = PyLong_FromLong(ER_UNIQUE_KEY_NEED_ALL_FIELDS_IN_PF)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNIQUE_KEY_NEED_ALL_FIELDS_IN_PF", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_PARTS_ERROR
    if (!(val = PyLong_FromLong(ER_NO_PARTS_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_PARTS_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_MGMT_ON_NONPARTITIONED
    if (!(val = PyLong_FromLong(ER_PARTITION_MGMT_ON_NONPARTITIONED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_MGMT_ON_NONPARTITIONED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FOREIGN_KEY_ON_PARTITIONED
    if (!(val = PyLong_FromLong(ER_FOREIGN_KEY_ON_PARTITIONED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FOREIGN_KEY_ON_PARTITIONED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DROP_PARTITION_NON_EXISTENT
    if (!(val = PyLong_FromLong(ER_DROP_PARTITION_NON_EXISTENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DROP_PARTITION_NON_EXISTENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DROP_LAST_PARTITION
    if (!(val = PyLong_FromLong(ER_DROP_LAST_PARTITION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DROP_LAST_PARTITION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_COALESCE_ONLY_ON_HASH_PARTITION
    if (!(val = PyLong_FromLong(ER_COALESCE_ONLY_ON_HASH_PARTITION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_COALESCE_ONLY_ON_HASH_PARTITION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_REORG_HASH_ONLY_ON_SAME_NO
    if (!(val = PyLong_FromLong(ER_REORG_HASH_ONLY_ON_SAME_NO)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_REORG_HASH_ONLY_ON_SAME_NO", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_REORG_NO_PARAM_ERROR
    if (!(val = PyLong_FromLong(ER_REORG_NO_PARAM_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_REORG_NO_PARAM_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ONLY_ON_RANGE_LIST_PARTITION
    if (!(val = PyLong_FromLong(ER_ONLY_ON_RANGE_LIST_PARTITION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ONLY_ON_RANGE_LIST_PARTITION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ADD_PARTITION_SUBPART_ERROR
    if (!(val = PyLong_FromLong(ER_ADD_PARTITION_SUBPART_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ADD_PARTITION_SUBPART_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ADD_PARTITION_NO_NEW_PARTITION
    if (!(val = PyLong_FromLong(ER_ADD_PARTITION_NO_NEW_PARTITION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ADD_PARTITION_NO_NEW_PARTITION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_COALESCE_PARTITION_NO_PARTITION
    if (!(val = PyLong_FromLong(ER_COALESCE_PARTITION_NO_PARTITION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_COALESCE_PARTITION_NO_PARTITION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_REORG_PARTITION_NOT_EXIST
    if (!(val = PyLong_FromLong(ER_REORG_PARTITION_NOT_EXIST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_REORG_PARTITION_NOT_EXIST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SAME_NAME_PARTITION
    if (!(val = PyLong_FromLong(ER_SAME_NAME_PARTITION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SAME_NAME_PARTITION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_BINLOG_ERROR
    if (!(val = PyLong_FromLong(ER_NO_BINLOG_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_BINLOG_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CONSECUTIVE_REORG_PARTITIONS
    if (!(val = PyLong_FromLong(ER_CONSECUTIVE_REORG_PARTITIONS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CONSECUTIVE_REORG_PARTITIONS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_REORG_OUTSIDE_RANGE
    if (!(val = PyLong_FromLong(ER_REORG_OUTSIDE_RANGE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_REORG_OUTSIDE_RANGE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_FUNCTION_FAILURE
    if (!(val = PyLong_FromLong(ER_PARTITION_FUNCTION_FAILURE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_FUNCTION_FAILURE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PART_STATE_ERROR
    if (!(val = PyLong_FromLong(ER_PART_STATE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PART_STATE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LIMITED_PART_RANGE
    if (!(val = PyLong_FromLong(ER_LIMITED_PART_RANGE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LIMITED_PART_RANGE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PLUGIN_IS_NOT_LOADED
    if (!(val = PyLong_FromLong(ER_PLUGIN_IS_NOT_LOADED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PLUGIN_IS_NOT_LOADED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_VALUE
    if (!(val = PyLong_FromLong(ER_WRONG_VALUE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_VALUE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_PARTITION_FOR_GIVEN_VALUE
    if (!(val = PyLong_FromLong(ER_NO_PARTITION_FOR_GIVEN_VALUE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_PARTITION_FOR_GIVEN_VALUE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FILEGROUP_OPTION_ONLY_ONCE
    if (!(val = PyLong_FromLong(ER_FILEGROUP_OPTION_ONLY_ONCE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FILEGROUP_OPTION_ONLY_ONCE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CREATE_FILEGROUP_FAILED
    if (!(val = PyLong_FromLong(ER_CREATE_FILEGROUP_FAILED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CREATE_FILEGROUP_FAILED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DROP_FILEGROUP_FAILED
    if (!(val = PyLong_FromLong(ER_DROP_FILEGROUP_FAILED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DROP_FILEGROUP_FAILED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLESPACE_AUTO_EXTEND_ERROR
    if (!(val = PyLong_FromLong(ER_TABLESPACE_AUTO_EXTEND_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLESPACE_AUTO_EXTEND_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_SIZE_NUMBER
    if (!(val = PyLong_FromLong(ER_WRONG_SIZE_NUMBER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_SIZE_NUMBER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SIZE_OVERFLOW_ERROR
    if (!(val = PyLong_FromLong(ER_SIZE_OVERFLOW_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SIZE_OVERFLOW_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ALTER_FILEGROUP_FAILED
    if (!(val = PyLong_FromLong(ER_ALTER_FILEGROUP_FAILED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ALTER_FILEGROUP_FAILED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BINLOG_ROW_LOGGING_FAILED
    if (!(val = PyLong_FromLong(ER_BINLOG_ROW_LOGGING_FAILED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BINLOG_ROW_LOGGING_FAILED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BINLOG_ROW_WRONG_TABLE_DEF
    if (!(val = PyLong_FromLong(ER_BINLOG_ROW_WRONG_TABLE_DEF)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BINLOG_ROW_WRONG_TABLE_DEF", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BINLOG_ROW_RBR_TO_SBR
    if (!(val = PyLong_FromLong(ER_BINLOG_ROW_RBR_TO_SBR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BINLOG_ROW_RBR_TO_SBR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_ALREADY_EXISTS
    if (!(val = PyLong_FromLong(ER_EVENT_ALREADY_EXISTS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_ALREADY_EXISTS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_STORE_FAILED
    if (!(val = PyLong_FromLong(ER_EVENT_STORE_FAILED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_STORE_FAILED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_DOES_NOT_EXIST
    if (!(val = PyLong_FromLong(ER_EVENT_DOES_NOT_EXIST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_DOES_NOT_EXIST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_CANT_ALTER
    if (!(val = PyLong_FromLong(ER_EVENT_CANT_ALTER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_CANT_ALTER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_DROP_FAILED
    if (!(val = PyLong_FromLong(ER_EVENT_DROP_FAILED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_DROP_FAILED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_INTERVAL_NOT_POSITIVE_OR_TOO_BIG
    if (!(val = PyLong_FromLong(ER_EVENT_INTERVAL_NOT_POSITIVE_OR_TOO_BIG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_INTERVAL_NOT_POSITIVE_OR_TOO_BIG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_ENDS_BEFORE_STARTS
    if (!(val = PyLong_FromLong(ER_EVENT_ENDS_BEFORE_STARTS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_ENDS_BEFORE_STARTS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_EXEC_TIME_IN_THE_PAST
    if (!(val = PyLong_FromLong(ER_EVENT_EXEC_TIME_IN_THE_PAST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_EXEC_TIME_IN_THE_PAST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_OPEN_TABLE_FAILED
    if (!(val = PyLong_FromLong(ER_EVENT_OPEN_TABLE_FAILED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_OPEN_TABLE_FAILED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_NEITHER_M_EXPR_NOR_M_AT
    if (!(val = PyLong_FromLong(ER_EVENT_NEITHER_M_EXPR_NOR_M_AT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_NEITHER_M_EXPR_NOR_M_AT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_COL_COUNT_DOESNT_MATCH_CORRUPTED
    if (!(val = PyLong_FromLong(ER_COL_COUNT_DOESNT_MATCH_CORRUPTED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_COL_COUNT_DOESNT_MATCH_CORRUPTED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANNOT_LOAD_FROM_TABLE
    if (!(val = PyLong_FromLong(ER_CANNOT_LOAD_FROM_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANNOT_LOAD_FROM_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_CANNOT_DELETE
    if (!(val = PyLong_FromLong(ER_EVENT_CANNOT_DELETE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_CANNOT_DELETE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_COMPILE_ERROR
    if (!(val = PyLong_FromLong(ER_EVENT_COMPILE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_COMPILE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_SAME_NAME
    if (!(val = PyLong_FromLong(ER_EVENT_SAME_NAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_SAME_NAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_DATA_TOO_LONG
    if (!(val = PyLong_FromLong(ER_EVENT_DATA_TOO_LONG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_DATA_TOO_LONG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DROP_INDEX_FK
    if (!(val = PyLong_FromLong(ER_DROP_INDEX_FK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DROP_INDEX_FK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_DEPRECATED_SYNTAX_WITH_VER
    if (!(val = PyLong_FromLong(ER_WARN_DEPRECATED_SYNTAX_WITH_VER)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_DEPRECATED_SYNTAX_WITH_VER", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_WRITE_LOCK_LOG_TABLE
    if (!(val = PyLong_FromLong(ER_CANT_WRITE_LOCK_LOG_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_WRITE_LOCK_LOG_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_LOCK_LOG_TABLE
    if (!(val = PyLong_FromLong(ER_CANT_LOCK_LOG_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_LOCK_LOG_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FOREIGN_DUPLICATE_KEY
    if (!(val = PyLong_FromLong(ER_FOREIGN_DUPLICATE_KEY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FOREIGN_DUPLICATE_KEY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_COL_COUNT_DOESNT_MATCH_PLEASE_UPDATE
    if (!(val = PyLong_FromLong(ER_COL_COUNT_DOESNT_MATCH_PLEASE_UPDATE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_COL_COUNT_DOESNT_MATCH_PLEASE_UPDATE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TEMP_TABLE_PREVENTS_SWITCH_OUT_OF_RBR
    if (!(val = PyLong_FromLong(ER_TEMP_TABLE_PREVENTS_SWITCH_OUT_OF_RBR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TEMP_TABLE_PREVENTS_SWITCH_OUT_OF_RBR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_STORED_FUNCTION_PREVENTS_SWITCH_BINLOG_FORMAT
    if (!(val = PyLong_FromLong(ER_STORED_FUNCTION_PREVENTS_SWITCH_BINLOG_FORMAT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_STORED_FUNCTION_PREVENTS_SWITCH_BINLOG_FORMAT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NDB_CANT_SWITCH_BINLOG_FORMAT
    if (!(val = PyLong_FromLong(ER_NDB_CANT_SWITCH_BINLOG_FORMAT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NDB_CANT_SWITCH_BINLOG_FORMAT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_NO_TEMPORARY
    if (!(val = PyLong_FromLong(ER_PARTITION_NO_TEMPORARY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_NO_TEMPORARY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_CONST_DOMAIN_ERROR
    if (!(val = PyLong_FromLong(ER_PARTITION_CONST_DOMAIN_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_CONST_DOMAIN_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_FUNCTION_IS_NOT_ALLOWED
    if (!(val = PyLong_FromLong(ER_PARTITION_FUNCTION_IS_NOT_ALLOWED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_FUNCTION_IS_NOT_ALLOWED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DDL_LOG_ERROR
    if (!(val = PyLong_FromLong(ER_DDL_LOG_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DDL_LOG_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NULL_IN_VALUES_LESS_THAN
    if (!(val = PyLong_FromLong(ER_NULL_IN_VALUES_LESS_THAN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NULL_IN_VALUES_LESS_THAN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_PARTITION_NAME
    if (!(val = PyLong_FromLong(ER_WRONG_PARTITION_NAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_PARTITION_NAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_CHANGE_TX_ISOLATION
    if (!(val = PyLong_FromLong(ER_CANT_CHANGE_TX_ISOLATION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_CHANGE_TX_ISOLATION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DUP_ENTRY_AUTOINCREMENT_CASE
    if (!(val = PyLong_FromLong(ER_DUP_ENTRY_AUTOINCREMENT_CASE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DUP_ENTRY_AUTOINCREMENT_CASE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_MODIFY_QUEUE_ERROR
    if (!(val = PyLong_FromLong(ER_EVENT_MODIFY_QUEUE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_MODIFY_QUEUE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_SET_VAR_ERROR
    if (!(val = PyLong_FromLong(ER_EVENT_SET_VAR_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_SET_VAR_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_MERGE_ERROR
    if (!(val = PyLong_FromLong(ER_PARTITION_MERGE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_MERGE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_ACTIVATE_LOG
    if (!(val = PyLong_FromLong(ER_CANT_ACTIVATE_LOG)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_ACTIVATE_LOG", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_RBR_NOT_AVAILABLE
    if (!(val = PyLong_FromLong(ER_RBR_NOT_AVAILABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_RBR_NOT_AVAILABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BASE64_DECODE_ERROR
    if (!(val = PyLong_FromLong(ER_BASE64_DECODE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BASE64_DECODE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_RECURSION_FORBIDDEN
    if (!(val = PyLong_FromLong(ER_EVENT_RECURSION_FORBIDDEN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_RECURSION_FORBIDDEN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENTS_DB_ERROR
    if (!(val = PyLong_FromLong(ER_EVENTS_DB_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENTS_DB_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ONLY_INTEGERS_ALLOWED
    if (!(val = PyLong_FromLong(ER_ONLY_INTEGERS_ALLOWED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ONLY_INTEGERS_ALLOWED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_UNSUPORTED_LOG_ENGINE
    if (!(val = PyLong_FromLong(ER_UNSUPORTED_LOG_ENGINE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_UNSUPORTED_LOG_ENGINE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BAD_LOG_STATEMENT
    if (!(val = PyLong_FromLong(ER_BAD_LOG_STATEMENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BAD_LOG_STATEMENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_RENAME_LOG_TABLE
    if (!(val = PyLong_FromLong(ER_CANT_RENAME_LOG_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_RENAME_LOG_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_PARAMCOUNT_TO_NATIVE_FCT
    if (!(val = PyLong_FromLong(ER_WRONG_PARAMCOUNT_TO_NATIVE_FCT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_PARAMCOUNT_TO_NATIVE_FCT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_PARAMETERS_TO_NATIVE_FCT
    if (!(val = PyLong_FromLong(ER_WRONG_PARAMETERS_TO_NATIVE_FCT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_PARAMETERS_TO_NATIVE_FCT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WRONG_PARAMETERS_TO_STORED_FCT
    if (!(val = PyLong_FromLong(ER_WRONG_PARAMETERS_TO_STORED_FCT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WRONG_PARAMETERS_TO_STORED_FCT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NATIVE_FCT_NAME_COLLISION
    if (!(val = PyLong_FromLong(ER_NATIVE_FCT_NAME_COLLISION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NATIVE_FCT_NAME_COLLISION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DUP_ENTRY_WITH_KEY_NAME
    if (!(val = PyLong_FromLong(ER_DUP_ENTRY_WITH_KEY_NAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DUP_ENTRY_WITH_KEY_NAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BINLOG_PURGE_EMFILE
    if (!(val = PyLong_FromLong(ER_BINLOG_PURGE_EMFILE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BINLOG_PURGE_EMFILE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_CANNOT_CREATE_IN_THE_PAST
    if (!(val = PyLong_FromLong(ER_EVENT_CANNOT_CREATE_IN_THE_PAST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_CANNOT_CREATE_IN_THE_PAST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_CANNOT_ALTER_IN_THE_PAST
    if (!(val = PyLong_FromLong(ER_EVENT_CANNOT_ALTER_IN_THE_PAST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_CANNOT_ALTER_IN_THE_PAST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_INCIDENT
    if (!(val = PyLong_FromLong(ER_SLAVE_INCIDENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_INCIDENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_PARTITION_FOR_GIVEN_VALUE_SILENT
    if (!(val = PyLong_FromLong(ER_NO_PARTITION_FOR_GIVEN_VALUE_SILENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_PARTITION_FOR_GIVEN_VALUE_SILENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BINLOG_UNSAFE_STATEMENT
    if (!(val = PyLong_FromLong(ER_BINLOG_UNSAFE_STATEMENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BINLOG_UNSAFE_STATEMENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_FATAL_ERROR
    if (!(val = PyLong_FromLong(ER_SLAVE_FATAL_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_FATAL_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_RELAY_LOG_READ_FAILURE
    if (!(val = PyLong_FromLong(ER_SLAVE_RELAY_LOG_READ_FAILURE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_RELAY_LOG_READ_FAILURE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_RELAY_LOG_WRITE_FAILURE
    if (!(val = PyLong_FromLong(ER_SLAVE_RELAY_LOG_WRITE_FAILURE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_RELAY_LOG_WRITE_FAILURE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_CREATE_EVENT_FAILURE
    if (!(val = PyLong_FromLong(ER_SLAVE_CREATE_EVENT_FAILURE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_CREATE_EVENT_FAILURE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_MASTER_COM_FAILURE
    if (!(val = PyLong_FromLong(ER_SLAVE_MASTER_COM_FAILURE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_MASTER_COM_FAILURE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_BINLOG_LOGGING_IMPOSSIBLE
    if (!(val = PyLong_FromLong(ER_BINLOG_LOGGING_IMPOSSIBLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_BINLOG_LOGGING_IMPOSSIBLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_NO_CREATION_CTX
    if (!(val = PyLong_FromLong(ER_VIEW_NO_CREATION_CTX)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_NO_CREATION_CTX", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VIEW_INVALID_CREATION_CTX
    if (!(val = PyLong_FromLong(ER_VIEW_INVALID_CREATION_CTX)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VIEW_INVALID_CREATION_CTX", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SR_INVALID_CREATION_CTX
    if (!(val = PyLong_FromLong(ER_SR_INVALID_CREATION_CTX)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SR_INVALID_CREATION_CTX", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRG_CORRUPTED_FILE
    if (!(val = PyLong_FromLong(ER_TRG_CORRUPTED_FILE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRG_CORRUPTED_FILE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRG_NO_CREATION_CTX
    if (!(val = PyLong_FromLong(ER_TRG_NO_CREATION_CTX)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRG_NO_CREATION_CTX", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRG_INVALID_CREATION_CTX
    if (!(val = PyLong_FromLong(ER_TRG_INVALID_CREATION_CTX)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRG_INVALID_CREATION_CTX", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EVENT_INVALID_CREATION_CTX
    if (!(val = PyLong_FromLong(ER_EVENT_INVALID_CREATION_CTX)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EVENT_INVALID_CREATION_CTX", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TRG_CANT_OPEN_TABLE
    if (!(val = PyLong_FromLong(ER_TRG_CANT_OPEN_TABLE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TRG_CANT_OPEN_TABLE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CANT_CREATE_SROUTINE
    if (!(val = PyLong_FromLong(ER_CANT_CREATE_SROUTINE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CANT_CREATE_SROUTINE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_AMBIGOUS_EXEC_MODE
    if (!(val = PyLong_FromLong(ER_SLAVE_AMBIGOUS_EXEC_MODE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_AMBIGOUS_EXEC_MODE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NO_FORMAT_DESCRIPTION_EVENT_BEFORE_BINLOG_STATEMENT
    if (!(val = PyLong_FromLong(ER_NO_FORMAT_DESCRIPTION_EVENT_BEFORE_BINLOG_STATEMENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NO_FORMAT_DESCRIPTION_EVENT_BEFORE_BINLOG_STATEMENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_CORRUPT_EVENT
    if (!(val = PyLong_FromLong(ER_SLAVE_CORRUPT_EVENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_CORRUPT_EVENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LOAD_DATA_INVALID_COLUMN
    if (!(val = PyLong_FromLong(ER_LOAD_DATA_INVALID_COLUMN)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LOAD_DATA_INVALID_COLUMN", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_LOG_PURGE_NO_FILE
    if (!(val = PyLong_FromLong(ER_LOG_PURGE_NO_FILE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_LOG_PURGE_NO_FILE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_XA_RBTIMEOUT
    if (!(val = PyLong_FromLong(ER_XA_RBTIMEOUT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_XA_RBTIMEOUT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_XA_RBDEADLOCK
    if (!(val = PyLong_FromLong(ER_XA_RBDEADLOCK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_XA_RBDEADLOCK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NEED_REPREPARE
    if (!(val = PyLong_FromLong(ER_NEED_REPREPARE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NEED_REPREPARE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DELAYED_NOT_SUPPORTED
    if (!(val = PyLong_FromLong(ER_DELAYED_NOT_SUPPORTED)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DELAYED_NOT_SUPPORTED", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_VARIABLE_IS_READONLY
    if (!(val = PyLong_FromLong(ER_VARIABLE_IS_READONLY)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_VARIABLE_IS_READONLY", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_WARN_ENGINE_TRANSACTION_ROLLBACK
    if (!(val = PyLong_FromLong(ER_WARN_ENGINE_TRANSACTION_ROLLBACK)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_WARN_ENGINE_TRANSACTION_ROLLBACK", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_HEARTBEAT_FAILURE
    if (!(val = PyLong_FromLong(ER_SLAVE_HEARTBEAT_FAILURE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_HEARTBEAT_FAILURE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SLAVE_HEARTBEAT_VALUE_OUT_OF_RANGE
    if (!(val = PyLong_FromLong(ER_SLAVE_HEARTBEAT_VALUE_OUT_OF_RANGE)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SLAVE_HEARTBEAT_VALUE_OUT_OF_RANGE", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_NDB_REPLICATION_SCHEMA_ERROR
    if (!(val = PyLong_FromLong(ER_NDB_REPLICATION_SCHEMA_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_NDB_REPLICATION_SCHEMA_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_CONFLICT_FN_PARSE_ERROR
    if (!(val = PyLong_FromLong(ER_CONFLICT_FN_PARSE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_CONFLICT_FN_PARSE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_EXCEPTIONS_WRITE_ERROR
    if (!(val = PyLong_FromLong(ER_EXCEPTIONS_WRITE_ERROR)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_EXCEPTIONS_WRITE_ERROR", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_LONG_TABLE_COMMENT
    if (!(val = PyLong_FromLong(ER_TOO_LONG_TABLE_COMMENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_LONG_TABLE_COMMENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_LONG_FIELD_COMMENT
    if (!(val = PyLong_FromLong(ER_TOO_LONG_FIELD_COMMENT)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_LONG_FIELD_COMMENT", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_FUNC_INEXISTENT_NAME_COLLISION
    if (!(val = PyLong_FromLong(ER_FUNC_INEXISTENT_NAME_COLLISION)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_FUNC_INEXISTENT_NAME_COLLISION", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_DATABASE_NAME
    if (!(val = PyLong_FromLong(ER_DATABASE_NAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_DATABASE_NAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TABLE_NAME
    if (!(val = PyLong_FromLong(ER_TABLE_NAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TABLE_NAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_PARTITION_NAME
    if (!(val = PyLong_FromLong(ER_PARTITION_NAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_PARTITION_NAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_SUBPARTITION_NAME
    if (!(val = PyLong_FromLong(ER_SUBPARTITION_NAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_SUBPARTITION_NAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TEMPORARY_NAME
    if (!(val = PyLong_FromLong(ER_TEMPORARY_NAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TEMPORARY_NAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_RENAMED_NAME
    if (!(val = PyLong_FromLong(ER_RENAMED_NAME)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_RENAMED_NAME", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_TOO_MANY_CONCURRENT_TRXS
    if (!(val = PyLong_FromLong(ER_TOO_MANY_CONCURRENT_TRXS)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_TOO_MANY_CONCURRENT_TRXS", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

#ifdef ER_ERROR_LAST
    if (!(val = PyLong_FromLong(ER_ERROR_LAST)))
        goto value_error;
    if (PyDict_SetItemString(ret, "ER_ERROR_LAST", val) == -1)
        goto set_error;
    Py_DECREF(val);
#endif

    return ret;
    
  set_error:
    Py_DECREF(val);
  value_error:
    Py_DECREF(ret);
    return NULL;
}
