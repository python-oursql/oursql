#!/usr/bin/env python
import time
import sys

file_template = """
/* generated on %(when)s */

enum _oursqlx_exception_type _oursqlx_exc_from_errno(int err) {
    switch (err) {
%(code)s
        default:
            if (err >= ER_ERROR_FIRST && err <= ER_ERROR_LAST)
                return _oursqlx_ProgrammingError;
            else if (err > CR_MIN_ERROR && err < CR_MAX_ERROR)
                return _oursqlx_InterfaceError;
    }
    return _oursqlx_UnknownError;
}
"""

case_template = """
#ifdef %(const)s
        case %(const)s:
#endif
"""
return_template = """
            return %(exc)s;
"""

data = dict(
    _oursqlx_DataError="""
        CR_DATA_TRUNCATED
        ER_DIVISION_BY_ZERO
        ER_DUPLICATED_VALUE_IN_TYPE
        ER_TRUNCATED_WRONG_VALUE
        ER_TRUNCATED_WRONG_VALUE_FOR_FIELD
        ER_WARN_DATA_OUT_OF_RANGE
        ER_WARN_NULL_TO_NOTNULL
        ER_WRONG_VALUE
    """,
    _oursqlx_IntegrityError="""
        ER_DROP_INDEX_FK
        ER_DUP_ENTRY
        ER_DUP_ENTRY_AUTOINCREMENT_CASE
        ER_DUP_UNIQUE
        ER_FOREIGN_DUPLICATE_KEY
        ER_NO_REFERENCED_ROW
        ER_NO_REFERENCED_ROW_2
        ER_ROW_IS_REFERENCED
        ER_ROW_IS_REFERENCED_2
    """,
    _oursqlx_InternalError="""
        ER_DUP_KEY
        ER_FILSORT_ABORT
        ER_KEY_NOT_FOUND
    """,
    _oursqlx_NotSupportedError="""
        CR_NOT_IMPLEMENTED
        ER_CHECK_NOT_IMPLEMENTED
        ER_DELAYED_NOT_SUPPORTED
        ER_DUMP_NOT_IMPLEMENTED
        ER_FOREIGN_KEY_ON_PARTITIONED
        ER_ILLEGAL_HA
        ER_ILLEGAL_HA_CREATE_OPTION
        ER_ILLEGAL_REFERENCE
        ER_NDB_CANT_SWITCH_BINLOG_FORMAT
        ER_NOT_SUPPORTED_AUTH_MODE
        ER_NOT_SUPPORTED_YET
        ER_NO_RAID_COMPILED
        ER_NULL_COLUMN_IN_INDEX
        ER_PARTITION_FUNCTION_FAILURE
        ER_SLAVE_IGNORED_SSL_PARAMS
        ER_SP_NO_AGGREGATE
        ER_SP_SUBSELECT_NYI
        ER_TABLESPACE_AUTO_EXTEND_ERROR
        ER_TABLE_CANT_HANDLE_AUTO_INCREMENT
        ER_TABLE_CANT_HANDLE_BLOB
        ER_TABLE_CANT_HANDLE_FT
        ER_TABLE_CANT_HANDLE_SPKEYS
        ER_UNSUPPORTED_EXTENSION
        ER_UNSUPPORTED_PS
        ER_WARN_ENGINE_TRANSACTION_ROLLBACK
    """,
    _oursqlx_OperationalError="""
        CR_SERVER_GONE_ERROR
        CR_SERVER_LOST
        ER_ABORTING_CONNECTION
        ER_ALTER_FILEGROUP_FAILED
        ER_AUTOINC_READ_FAILED
        ER_BINLOG_PURGE_FATAL_ERR
        ER_BINLOG_ROW_LOGGING_FAILED
        ER_CANNOT_USER
        ER_CANT_CREATE_DB
        ER_CANT_CREATE_FILE
        ER_CANT_CREATE_HANDLER_FILE
        ER_CANT_CREATE_TABLE
        ER_CANT_CREATE_THREAD
        ER_CANT_DELETE_FILE
        ER_CANT_FIND_SYSTEM_REC
        ER_CANT_GET_STAT
        ER_CANT_GET_WD
        ER_CANT_LOCK
        ER_CANT_OPEN_FILE
        ER_CANT_OPEN_LIBRARY
        ER_CANT_READ_DIR
        ER_CANT_SET_WD
        ER_CHECKREAD
        ER_CONFLICT_FN_PARSE_ERROR
        ER_CONNECT_TO_MASTER
        ER_CRASHED_ON_REPAIR
        ER_CRASHED_ON_USAGE
        ER_CREATE_FILEGROUP_FAILED
        ER_DB_DROP_DELETE
        ER_DB_DROP_RMDIR
        ER_DDL_LOG_ERROR
        ER_DISK_FULL
        ER_DROP_FILEGROUP_FAILED
        ER_ERROR_DURING_CHECKPOINT
        ER_ERROR_DURING_COMMIT
        ER_ERROR_DURING_FLUSH_LOGS
        ER_ERROR_DURING_ROLLBACK
        ER_ERROR_ON_CLOSE
        ER_ERROR_ON_READ
        ER_ERROR_ON_RENAME
        ER_ERROR_ON_WRITE
        ER_ERROR_WHEN_EXECUTING_COMMAND
        ER_EVENT_CANNOT_DELETE
        ER_EVENT_CANT_ALTER
        ER_EVENT_COMPILE_ERROR
        ER_EVENT_DROP_FAILED
        ER_EVENT_MODIFY_QUEUE_ERROR
        ER_EVENT_OPEN_TABLE_FAILED
        ER_EVENT_SET_VAR_ERROR
        ER_EVENT_STORE_FAILED
        ER_EXCEPTIONS_WRITE_ERROR
        ER_FAILED_ROUTINE_BREAK_BINLOG
        ER_FILE_NOT_FOUND
        ER_FILE_USED
        ER_FSEEK_FAIL
        ER_GET_ERRMSG
        ER_GET_ERRNO
        ER_GET_TEMPORARY_ERRMSG
        ER_INDEX_REBUILD
        ER_IO_ERR_LOG_INDEX_READ
        ER_LOG_PURGE_UNKNOWN_ERR
        ER_MASTER
        ER_MASTER_FATAL_ERROR_READING_BINLOG
        ER_MASTER_INFO
        ER_MASTER_NET_READ
        ER_MASTER_NET_WRITE
        ER_NET_ERROR_ON_WRITE
        ER_NET_FCNTL_ERROR
        ER_NET_PACKETS_OUT_OF_ORDER
        ER_NET_READ_ERROR
        ER_NET_READ_ERROR_FROM_PIPE
        ER_NET_READ_INTERRUPTED
        ER_NET_UNCOMPRESS_ERROR
        ER_NET_WRITE_INTERRUPTED
        ER_NO_FILE_MAPPING
        ER_PROC_AUTO_GRANT_FAIL
        ER_PROC_AUTO_REVOKE_FAIL
        ER_QUERY_ON_MASTER
        ER_REGEXP_ERROR
        ER_RELAY_LOG_FAIL
        ER_RELAY_LOG_INIT
        ER_SLAVE_THREAD
        ER_SP_CANT_ALTER
        ER_SP_DROP_FAILED
        ER_SP_PROC_TABLE_CORRUPT
        ER_SP_STORE_FAILED
        ER_UNEXPECTED_EOF
        ER_VIEW_CHECKSUM
        ER_WARNING_NOT_COMPLETE_ROLLBACK
        ER_WSAS_FAILED
        ER_XAER_RMERR
    """,
    _oursqlx_PermissionsError="""
        ER_ACCESS_DENIED_ERROR
        ER_BINLOG_CREATE_ROUTINE_NEED_SUPER
        ER_CANT_CREATE_USER_WITH_GRANT
        ER_COLUMNACCESS_DENIED_ERROR
        ER_DBACCESS_DENIED_ERROR
        ER_HOST_NOT_PRIVILEGED
        ER_KILL_DENIED_ERROR
        ER_NO_PERMISSION_TO_CREATE_USER
        ER_PASSWORD_NOT_ALLOWED
        ER_PROCACCESS_DENIED_ERROR
        ER_SPECIFIC_ACCESS_DENIED_ERROR
        ER_TABLEACCESS_DENIED_ERROR
        ER_VIEW_NO_EXPLAIN
        ER_VIEW_OTHER_USER
    """,
)

def main(outfile):
    output = []
    for exc, consts in sorted(data.items()):
        for const in consts.split():
            output.append(case_template % dict(const=const))
        output.append(return_template % dict(exc=exc))
    outfile.write(file_template % dict(
        when=time.asctime(),
        code=''.join(output),
    ))

if __name__ == '__main__':
    main(open(sys.argv[1], 'w'))
