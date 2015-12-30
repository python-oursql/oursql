
/* generated on Thu Jan 28 11:05:33 2010 */

enum _oursqlx_exception_type _oursqlx_exc_from_errno(int err) {
    switch (err) {

#ifdef CR_DATA_TRUNCATED
        case CR_DATA_TRUNCATED:
#endif

#ifdef ER_DIVISION_BY_ZERO
        case ER_DIVISION_BY_ZERO:
#endif

#ifdef ER_DUPLICATED_VALUE_IN_TYPE
        case ER_DUPLICATED_VALUE_IN_TYPE:
#endif

#ifdef ER_TRUNCATED_WRONG_VALUE
        case ER_TRUNCATED_WRONG_VALUE:
#endif

#ifdef ER_TRUNCATED_WRONG_VALUE_FOR_FIELD
        case ER_TRUNCATED_WRONG_VALUE_FOR_FIELD:
#endif

#ifdef ER_WARN_DATA_OUT_OF_RANGE
        case ER_WARN_DATA_OUT_OF_RANGE:
#endif

#ifdef ER_WARN_NULL_TO_NOTNULL
        case ER_WARN_NULL_TO_NOTNULL:
#endif

#ifdef ER_WRONG_VALUE
        case ER_WRONG_VALUE:
#endif

            return _oursqlx_DataError;

#ifdef ER_DROP_INDEX_FK
        case ER_DROP_INDEX_FK:
#endif

#ifdef ER_DUP_ENTRY
        case ER_DUP_ENTRY:
#endif

#ifdef ER_DUP_ENTRY_AUTOINCREMENT_CASE
        case ER_DUP_ENTRY_AUTOINCREMENT_CASE:
#endif

#ifdef ER_DUP_UNIQUE
        case ER_DUP_UNIQUE:
#endif

#ifdef ER_FOREIGN_DUPLICATE_KEY
        case ER_FOREIGN_DUPLICATE_KEY:
#endif

#ifdef ER_NO_REFERENCED_ROW
        case ER_NO_REFERENCED_ROW:
#endif

#ifdef ER_NO_REFERENCED_ROW_2
        case ER_NO_REFERENCED_ROW_2:
#endif

#ifdef ER_ROW_IS_REFERENCED
        case ER_ROW_IS_REFERENCED:
#endif

#ifdef ER_ROW_IS_REFERENCED_2
        case ER_ROW_IS_REFERENCED_2:
#endif

            return _oursqlx_IntegrityError;

#ifdef ER_DUP_KEY
        case ER_DUP_KEY:
#endif

#ifdef ER_FILSORT_ABORT
        case ER_FILSORT_ABORT:
#endif

#ifdef ER_KEY_NOT_FOUND
        case ER_KEY_NOT_FOUND:
#endif

            return _oursqlx_InternalError;

#ifdef CR_NOT_IMPLEMENTED
        case CR_NOT_IMPLEMENTED:
#endif

#ifdef ER_CHECK_NOT_IMPLEMENTED
        case ER_CHECK_NOT_IMPLEMENTED:
#endif

#ifdef ER_DELAYED_NOT_SUPPORTED
        case ER_DELAYED_NOT_SUPPORTED:
#endif

#ifdef ER_DUMP_NOT_IMPLEMENTED
        case ER_DUMP_NOT_IMPLEMENTED:
#endif

#ifdef ER_FOREIGN_KEY_ON_PARTITIONED
        case ER_FOREIGN_KEY_ON_PARTITIONED:
#endif

#ifdef ER_ILLEGAL_HA
        case ER_ILLEGAL_HA:
#endif

#ifdef ER_ILLEGAL_HA_CREATE_OPTION
        case ER_ILLEGAL_HA_CREATE_OPTION:
#endif

#ifdef ER_ILLEGAL_REFERENCE
        case ER_ILLEGAL_REFERENCE:
#endif

#ifdef ER_NDB_CANT_SWITCH_BINLOG_FORMAT
        case ER_NDB_CANT_SWITCH_BINLOG_FORMAT:
#endif

#ifdef ER_NOT_SUPPORTED_AUTH_MODE
        case ER_NOT_SUPPORTED_AUTH_MODE:
#endif

#ifdef ER_NOT_SUPPORTED_YET
        case ER_NOT_SUPPORTED_YET:
#endif

#ifdef ER_NO_RAID_COMPILED
        case ER_NO_RAID_COMPILED:
#endif

#ifdef ER_NULL_COLUMN_IN_INDEX
        case ER_NULL_COLUMN_IN_INDEX:
#endif

#ifdef ER_PARTITION_FUNCTION_FAILURE
        case ER_PARTITION_FUNCTION_FAILURE:
#endif

#ifdef ER_SLAVE_IGNORED_SSL_PARAMS
        case ER_SLAVE_IGNORED_SSL_PARAMS:
#endif

#ifdef ER_SP_NO_AGGREGATE
        case ER_SP_NO_AGGREGATE:
#endif

#ifdef ER_SP_SUBSELECT_NYI
        case ER_SP_SUBSELECT_NYI:
#endif

#ifdef ER_TABLESPACE_AUTO_EXTEND_ERROR
        case ER_TABLESPACE_AUTO_EXTEND_ERROR:
#endif

#ifdef ER_TABLE_CANT_HANDLE_AUTO_INCREMENT
        case ER_TABLE_CANT_HANDLE_AUTO_INCREMENT:
#endif

#ifdef ER_TABLE_CANT_HANDLE_BLOB
        case ER_TABLE_CANT_HANDLE_BLOB:
#endif

#ifdef ER_TABLE_CANT_HANDLE_FT
        case ER_TABLE_CANT_HANDLE_FT:
#endif

#ifdef ER_TABLE_CANT_HANDLE_SPKEYS
        case ER_TABLE_CANT_HANDLE_SPKEYS:
#endif

#ifdef ER_UNSUPPORTED_EXTENSION
        case ER_UNSUPPORTED_EXTENSION:
#endif

#ifdef ER_UNSUPPORTED_PS
        case ER_UNSUPPORTED_PS:
#endif

#ifdef ER_WARN_ENGINE_TRANSACTION_ROLLBACK
        case ER_WARN_ENGINE_TRANSACTION_ROLLBACK:
#endif

            return _oursqlx_NotSupportedError;

#ifdef CR_SERVER_GONE_ERROR
        case CR_SERVER_GONE_ERROR:
#endif

#ifdef CR_SERVER_LOST
        case CR_SERVER_LOST:
#endif

#ifdef ER_ABORTING_CONNECTION
        case ER_ABORTING_CONNECTION:
#endif

#ifdef ER_ALTER_FILEGROUP_FAILED
        case ER_ALTER_FILEGROUP_FAILED:
#endif

#ifdef ER_AUTOINC_READ_FAILED
        case ER_AUTOINC_READ_FAILED:
#endif

#ifdef ER_BINLOG_PURGE_FATAL_ERR
        case ER_BINLOG_PURGE_FATAL_ERR:
#endif

#ifdef ER_BINLOG_ROW_LOGGING_FAILED
        case ER_BINLOG_ROW_LOGGING_FAILED:
#endif

#ifdef ER_CANNOT_USER
        case ER_CANNOT_USER:
#endif

#ifdef ER_CANT_CREATE_DB
        case ER_CANT_CREATE_DB:
#endif

#ifdef ER_CANT_CREATE_FILE
        case ER_CANT_CREATE_FILE:
#endif

#ifdef ER_CANT_CREATE_HANDLER_FILE
        case ER_CANT_CREATE_HANDLER_FILE:
#endif

#ifdef ER_CANT_CREATE_TABLE
        case ER_CANT_CREATE_TABLE:
#endif

#ifdef ER_CANT_CREATE_THREAD
        case ER_CANT_CREATE_THREAD:
#endif

#ifdef ER_CANT_DELETE_FILE
        case ER_CANT_DELETE_FILE:
#endif

#ifdef ER_CANT_FIND_SYSTEM_REC
        case ER_CANT_FIND_SYSTEM_REC:
#endif

#ifdef ER_CANT_GET_STAT
        case ER_CANT_GET_STAT:
#endif

#ifdef ER_CANT_GET_WD
        case ER_CANT_GET_WD:
#endif

#ifdef ER_CANT_LOCK
        case ER_CANT_LOCK:
#endif

#ifdef ER_CANT_OPEN_FILE
        case ER_CANT_OPEN_FILE:
#endif

#ifdef ER_CANT_OPEN_LIBRARY
        case ER_CANT_OPEN_LIBRARY:
#endif

#ifdef ER_CANT_READ_DIR
        case ER_CANT_READ_DIR:
#endif

#ifdef ER_CANT_SET_WD
        case ER_CANT_SET_WD:
#endif

#ifdef ER_CHECKREAD
        case ER_CHECKREAD:
#endif

#ifdef ER_CONFLICT_FN_PARSE_ERROR
        case ER_CONFLICT_FN_PARSE_ERROR:
#endif

#ifdef ER_CONNECT_TO_MASTER
        case ER_CONNECT_TO_MASTER:
#endif

#ifdef ER_CRASHED_ON_REPAIR
        case ER_CRASHED_ON_REPAIR:
#endif

#ifdef ER_CRASHED_ON_USAGE
        case ER_CRASHED_ON_USAGE:
#endif

#ifdef ER_CREATE_FILEGROUP_FAILED
        case ER_CREATE_FILEGROUP_FAILED:
#endif

#ifdef ER_DB_DROP_DELETE
        case ER_DB_DROP_DELETE:
#endif

#ifdef ER_DB_DROP_RMDIR
        case ER_DB_DROP_RMDIR:
#endif

#ifdef ER_DDL_LOG_ERROR
        case ER_DDL_LOG_ERROR:
#endif

#ifdef ER_DISK_FULL
        case ER_DISK_FULL:
#endif

#ifdef ER_DROP_FILEGROUP_FAILED
        case ER_DROP_FILEGROUP_FAILED:
#endif

#ifdef ER_ERROR_DURING_CHECKPOINT
        case ER_ERROR_DURING_CHECKPOINT:
#endif

#ifdef ER_ERROR_DURING_COMMIT
        case ER_ERROR_DURING_COMMIT:
#endif

#ifdef ER_ERROR_DURING_FLUSH_LOGS
        case ER_ERROR_DURING_FLUSH_LOGS:
#endif

#ifdef ER_ERROR_DURING_ROLLBACK
        case ER_ERROR_DURING_ROLLBACK:
#endif

#ifdef ER_ERROR_ON_CLOSE
        case ER_ERROR_ON_CLOSE:
#endif

#ifdef ER_ERROR_ON_READ
        case ER_ERROR_ON_READ:
#endif

#ifdef ER_ERROR_ON_RENAME
        case ER_ERROR_ON_RENAME:
#endif

#ifdef ER_ERROR_ON_WRITE
        case ER_ERROR_ON_WRITE:
#endif

#ifdef ER_ERROR_WHEN_EXECUTING_COMMAND
        case ER_ERROR_WHEN_EXECUTING_COMMAND:
#endif

#ifdef ER_EVENT_CANNOT_DELETE
        case ER_EVENT_CANNOT_DELETE:
#endif

#ifdef ER_EVENT_CANT_ALTER
        case ER_EVENT_CANT_ALTER:
#endif

#ifdef ER_EVENT_COMPILE_ERROR
        case ER_EVENT_COMPILE_ERROR:
#endif

#ifdef ER_EVENT_DROP_FAILED
        case ER_EVENT_DROP_FAILED:
#endif

#ifdef ER_EVENT_MODIFY_QUEUE_ERROR
        case ER_EVENT_MODIFY_QUEUE_ERROR:
#endif

#ifdef ER_EVENT_OPEN_TABLE_FAILED
        case ER_EVENT_OPEN_TABLE_FAILED:
#endif

#ifdef ER_EVENT_SET_VAR_ERROR
        case ER_EVENT_SET_VAR_ERROR:
#endif

#ifdef ER_EVENT_STORE_FAILED
        case ER_EVENT_STORE_FAILED:
#endif

#ifdef ER_EXCEPTIONS_WRITE_ERROR
        case ER_EXCEPTIONS_WRITE_ERROR:
#endif

#ifdef ER_FAILED_ROUTINE_BREAK_BINLOG
        case ER_FAILED_ROUTINE_BREAK_BINLOG:
#endif

#ifdef ER_FILE_NOT_FOUND
        case ER_FILE_NOT_FOUND:
#endif

#ifdef ER_FILE_USED
        case ER_FILE_USED:
#endif

#ifdef ER_FSEEK_FAIL
        case ER_FSEEK_FAIL:
#endif

#ifdef ER_GET_ERRMSG
        case ER_GET_ERRMSG:
#endif

#ifdef ER_GET_ERRNO
        case ER_GET_ERRNO:
#endif

#ifdef ER_GET_TEMPORARY_ERRMSG
        case ER_GET_TEMPORARY_ERRMSG:
#endif

#ifdef ER_INDEX_REBUILD
        case ER_INDEX_REBUILD:
#endif

#ifdef ER_IO_ERR_LOG_INDEX_READ
        case ER_IO_ERR_LOG_INDEX_READ:
#endif

#ifdef ER_LOG_PURGE_UNKNOWN_ERR
        case ER_LOG_PURGE_UNKNOWN_ERR:
#endif

#ifdef ER_MASTER
        case ER_MASTER:
#endif

#ifdef ER_MASTER_FATAL_ERROR_READING_BINLOG
        case ER_MASTER_FATAL_ERROR_READING_BINLOG:
#endif

#ifdef ER_MASTER_INFO
        case ER_MASTER_INFO:
#endif

#ifdef ER_MASTER_NET_READ
        case ER_MASTER_NET_READ:
#endif

#ifdef ER_MASTER_NET_WRITE
        case ER_MASTER_NET_WRITE:
#endif

#ifdef ER_NET_ERROR_ON_WRITE
        case ER_NET_ERROR_ON_WRITE:
#endif

#ifdef ER_NET_FCNTL_ERROR
        case ER_NET_FCNTL_ERROR:
#endif

#ifdef ER_NET_PACKETS_OUT_OF_ORDER
        case ER_NET_PACKETS_OUT_OF_ORDER:
#endif

#ifdef ER_NET_READ_ERROR
        case ER_NET_READ_ERROR:
#endif

#ifdef ER_NET_READ_ERROR_FROM_PIPE
        case ER_NET_READ_ERROR_FROM_PIPE:
#endif

#ifdef ER_NET_READ_INTERRUPTED
        case ER_NET_READ_INTERRUPTED:
#endif

#ifdef ER_NET_UNCOMPRESS_ERROR
        case ER_NET_UNCOMPRESS_ERROR:
#endif

#ifdef ER_NET_WRITE_INTERRUPTED
        case ER_NET_WRITE_INTERRUPTED:
#endif

#ifdef ER_NO_FILE_MAPPING
        case ER_NO_FILE_MAPPING:
#endif

#ifdef ER_PROC_AUTO_GRANT_FAIL
        case ER_PROC_AUTO_GRANT_FAIL:
#endif

#ifdef ER_PROC_AUTO_REVOKE_FAIL
        case ER_PROC_AUTO_REVOKE_FAIL:
#endif

#ifdef ER_QUERY_ON_MASTER
        case ER_QUERY_ON_MASTER:
#endif

#ifdef ER_REGEXP_ERROR
        case ER_REGEXP_ERROR:
#endif

#ifdef ER_RELAY_LOG_FAIL
        case ER_RELAY_LOG_FAIL:
#endif

#ifdef ER_RELAY_LOG_INIT
        case ER_RELAY_LOG_INIT:
#endif

#ifdef ER_SLAVE_THREAD
        case ER_SLAVE_THREAD:
#endif

#ifdef ER_SP_CANT_ALTER
        case ER_SP_CANT_ALTER:
#endif

#ifdef ER_SP_DROP_FAILED
        case ER_SP_DROP_FAILED:
#endif

#ifdef ER_SP_PROC_TABLE_CORRUPT
        case ER_SP_PROC_TABLE_CORRUPT:
#endif

#ifdef ER_SP_STORE_FAILED
        case ER_SP_STORE_FAILED:
#endif

#ifdef ER_UNEXPECTED_EOF
        case ER_UNEXPECTED_EOF:
#endif

#ifdef ER_VIEW_CHECKSUM
        case ER_VIEW_CHECKSUM:
#endif

#ifdef ER_WARNING_NOT_COMPLETE_ROLLBACK
        case ER_WARNING_NOT_COMPLETE_ROLLBACK:
#endif

#ifdef ER_WSAS_FAILED
        case ER_WSAS_FAILED:
#endif

#ifdef ER_XAER_RMERR
        case ER_XAER_RMERR:
#endif

            return _oursqlx_OperationalError;

#ifdef ER_ACCESS_DENIED_ERROR
        case ER_ACCESS_DENIED_ERROR:
#endif

#ifdef ER_BINLOG_CREATE_ROUTINE_NEED_SUPER
        case ER_BINLOG_CREATE_ROUTINE_NEED_SUPER:
#endif

#ifdef ER_CANT_CREATE_USER_WITH_GRANT
        case ER_CANT_CREATE_USER_WITH_GRANT:
#endif

#ifdef ER_COLUMNACCESS_DENIED_ERROR
        case ER_COLUMNACCESS_DENIED_ERROR:
#endif

#ifdef ER_DBACCESS_DENIED_ERROR
        case ER_DBACCESS_DENIED_ERROR:
#endif

#ifdef ER_HOST_NOT_PRIVILEGED
        case ER_HOST_NOT_PRIVILEGED:
#endif

#ifdef ER_KILL_DENIED_ERROR
        case ER_KILL_DENIED_ERROR:
#endif

#ifdef ER_NO_PERMISSION_TO_CREATE_USER
        case ER_NO_PERMISSION_TO_CREATE_USER:
#endif

#ifdef ER_PASSWORD_NOT_ALLOWED
        case ER_PASSWORD_NOT_ALLOWED:
#endif

#ifdef ER_PROCACCESS_DENIED_ERROR
        case ER_PROCACCESS_DENIED_ERROR:
#endif

#ifdef ER_SPECIFIC_ACCESS_DENIED_ERROR
        case ER_SPECIFIC_ACCESS_DENIED_ERROR:
#endif

#ifdef ER_TABLEACCESS_DENIED_ERROR
        case ER_TABLEACCESS_DENIED_ERROR:
#endif

#ifdef ER_VIEW_NO_EXPLAIN
        case ER_VIEW_NO_EXPLAIN:
#endif

#ifdef ER_VIEW_OTHER_USER
        case ER_VIEW_OTHER_USER:
#endif

            return _oursqlx_PermissionsError;

        default:
           #if MYSQL_VERSION_ID >= 50700 
              for(unsigned int i = 0; i < sizeof(errmsg_section_start)/sizeof(int); ++i) {
                int min = errmsg_section_start[i];
                int max = errmsg_section_start[i] + errmsg_section_size[i] - 1;
                if ( err >= min && err <= max ) {
                  return _oursqlx_ProgrammingError;
                }             
              }
              if ( err > CR_MIN_ERROR && err < CR_MAX_ERROR) {
                 return _oursqlx_InterfaceError;
              }
           #else
              if (err >= ER_ERROR_FIRST && err <= ER_ERROR_LAST)
                  return _oursqlx_ProgrammingError;
              else if (err > CR_MIN_ERROR && err < CR_MAX_ERROR)
                  return _oursqlx_InterfaceError;
           #endif
    }
    return _oursqlx_UnknownError;
}
