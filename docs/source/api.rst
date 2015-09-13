.. currentmodule:: oursql

=============
API Reference
=============

:class:`Connection`
===================

.. class:: Connection([host, user, passwd,] db=None, port=0, unix_socket=None, connect_timeout=None, read_timeout=None, write_timeout=None, protocol=None, ssl=None, read_default_file=None, read_default_group=None, init_command=None, charset_dir=None, shared_memory_base_name=None, local_infile=False, require_secure_auth=False, report_truncation=True, compress=False, found_rows=True, use_unicode=True, charset='utf8', autoping=False, default_cursor=None, raise_on_warnings=True)
    
    Represents a connection to the MySQL server. All parameters which are not 
    provided will use MySQL's defaults. For the exact semantics, see the 
    documentation for the :mysqlfunc:`mysql_real_connect` and 
    :mysqlfunc:`mysql_options` functions.
    
    :param connect_timeout:
        If given, passed as the :c:data:`MYSQL_OPT_CONNECT_TIMEOUT` option.
    
    :param read_timeout:
        If given, passed as the :c:data:`MYSQL_OPT_READ_TIMEOUT` option.
    
    :param write_timeout:
        If given, passed as the :c:data:`MYSQL_OPT_WRITE_TIMEOUT` option.
    
    :param read_default_file:
        If given, passed as the :c:data:`MYSQL_READ_DEFAULT_FILE` option.
    
    :param read_default_group:
        If given, passed as the :c:data:`MYSQL_READ_DEFAULT_GROUP` option.
    
    :param init_command:
        If given, passed as the :c:data:`MYSQL_INIT_COMMAND` option.
    
    :param charset_dir:
        If given, passed as the :c:data:`MYSQL_SET_CHARSET_DIR` option.
    
    :param shared_memory_base_name:
        If given, passed as the :c:data:`MYSQL_SHARED_MEMORY_BASE_NAME` option.
    
    :param local_infile:
        If given, passes the :c:data:`MYSQL_OPT_LOCAL_INFILE` option.
    
    :param require_secure_auth:
        The value of this parameter is passed to the :c:data:`MYSQL_SECURE_AUTH` 
        option.
    
    :param report_truncation:
        The value of this parameter is passed to the 
        :c:data:`MYSQL_REPORT_DATA_TRUNCATION` option.
    
    :param compress:
        Determines whether the :c:data:`CLIENT_COMPRESS` flag will be enabled.
    
    :param found_rows:
        Determines whether the :c:data:`CLIENT_FOUND_ROWS` flag will be enabled.
    
    :param protocol:
        Controls which protocol MySQL uses to connect to the server. This can
        be one of ``None``, ``'tcp'``, ``'socket'``, ``'pipe'``, or 
        ``'memory'``. A *protocol* of ``None`` will use the default protocol, 
        and values otherwise correspond with the potential values of the 
        *protocol* option in the option file.
    
    :param ssl:
        Sets the SSL options for the client connection. This can either be 
        ``None`` or a dict where each key corresponds to a parameter of the 
        :mysqlfunc:`mysql_ssl_set` function, e.g. ``{'capath': '/etc/ssl/ca', 
        'cipher': 'DHE-RSA-AES256-SHA'}``. Unspecified keys are the same as 
        passing ``NULL`` as that parameter.
    
    :param use_unicode: 
        This parameter controls whether oursql will try to decode unicode 
        strings received from MySQL. If *use_unicode* is on, all strings 
        received will try to be decoded using the same codec listed in the 
        :attr:`charset` attribute of the connection object. 
        
        Disabling *use_unicode* will cause all strings coming in or going out
        to be treated as bytes; no encoding or decoding will ever be done. This
        should only be used as a last-resort if there is malformed data in the
        database.
    
    :param charset:
        Sets the charset that the connection uses. By default, oursql tries to
        set this to utf8. To disable setting the charset automatically, pass 
        ``charset=None``.
    
    :param autoping:
        Controls whether oursql tries to make sure that the MySQL server is 
        still there before making a query or retrieving results. This is done
        by calling the :meth:`ping` method on the connection.
    
    :param default_cursor:
        Sets the default cursor class that this connection will use for the 
        :meth:`cursor` method.
    
    :param raise_on_warnings:
        Determines whether an exception will be raised if a query causes a 
        warning. If this is enabled, a :exc:`CollatedWarningsError` will be
        raised immediately after the query is executed.

    .. method:: ping()
    
        Calls the :mysqlfunc:`mysql_ping` function. If autoconnection is 
        enabled, this will transparently reestablish the connection. The exact 
        semantics of what happens when a reconnection happens `are more 
        thoroughly documented in MySQL's developer reference manual`__.
        
        __ http://dev.mysql.com/doc/refman/5.0/en/auto-reconnect.html

    .. method:: commit()
    
        Commits the current active transaction on the connection.
    
    .. method:: rollback()
    
        Rolls back the current active transaction on the connection.
    
    .. method:: close()
    
        Completely closes the connection. None of the methods and most of the
        attributes on the connection will no longer be usable. This will also 
        rollback any active transaction on the connection.

    .. method:: cursor([cursor_class,] **cursor_options)
    
        Create a cursor associated with this connection. 
        
        :param cursor_class:
            Specify the class of the cursor returned. If nothing is passed, 
            use the :attr:`default_cursor` attribute.
        
        Extra options can be passed to the cursor by keyword:
        
        :keyword try_plain_query:
            If this is true, oursql will first attempt to run queries as 
            prepared statements, and then fall back to the plain query API if 
            MySQL refuses to parameterize the query. Otherwise, oursql will 
            only run plain queries if explicitly asked. See the 
            :meth:`Cursor.execute` method.
        
        :keyword show_table: 
            If this is true, the name of the table will be prepended to the 
            name of the column in the :attr:`~oursql.Cursor.description` 
            attribute of the cursor.
        
        :keyword string_limit: 
            Set a limit on the size of the buffer oursql will allocate when 
            fetching strings over the wire. If the *string_limit* is nonzero, 
            file-like objects will always be returned instead of strings. If 
            the size of the string value is greater than the *string_limit*, 
            the string will be streamed as necessary instead of fetched all at 
            once. Note: plain queries buffer incoming result differently, and 
            are therefore unaffected by the *string_limit*.

.. function:: connect(...)

    :func:`connect` is simply an alias to the :class:`Connection` class.

Connections can also be used as context managers::

    with some_connection as cursor:
        do_something_with(cursor)

This behaves the same way as :ref:`using a cursor as a context manager 
<cursor_context_manager>`.

Cursor classes
==============

Cursors of any sort should never be instantiated directly. Currently, the only
real difference between cursor classes is how they return fetched rows. 
Iterating over a cursor is the same as repeatedly calling 
:meth:`~Cursor.fetchone`::
    
    curs.execute('SELECT a, b FROM `some_table`')
    curs.execute('SELECT c, d FROM `some_other_table`')
    
    # result set one:
    for a, b in curs:
        do_whatever_with(a, b)
    
    # result set two:
    for c, d in curs:
        do_whatever_with(a, b)

.. _cursor_context_manager:

Cursors can also be used as context managers::

    with some_connection.cursor() as cursor:
        do_something_with(cursor)

Is equivalent to::

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

:class:`Cursor`
---------------

.. class:: Cursor(...)
    
    :class:`Cursor` instances represent rows as tuples. 
    
    .. method:: close()
    
        Close the cursor and discard the rest of the results. The cursor will
        immediately become unusable.
    
    .. method:: callproc(procname, params=())
        
        Supposedly, run a stored procedure. MySQL's C API has no direct call
        for this; you need to execute stored procedures with the CALL statement
        instead. Calling this method always raises a :exc:`NotSupportedError`.
    
    .. method:: execute(query, params=(), plain_query=False)
    
        Execute a query. If *plain_query* is true, run a plain, unparameterized
        query. MySQL cannot parameterize all kinds of statements, which makes
        it sometimes necessary to execute a plain query. If *plain_query* is 
        true and *params* is true, an exception will be raised as plain queries 
        cannot be parameterized.
        
        Plain queries also have some associated caveats:
        
        * Results will always be buffered client-side and will not be lazily
          fetched from the server.
        * The *string_limit* cursor option will be completely ignored.
    
    .. method:: executemany(query, parambatch)
    
        Execute the same query with different sets of parameters. This is more
        efficient than calling execute many times with the same query.
    
    .. method:: nextset()
        
        Move to the next result set. If there are any result sets left, this
        returns ``True``. Otherwise, ``None``.
    
    .. method:: fetchone()
        
        Fetch one row from the current result set. If the result set was
        previously exhausted, this returns ``None`` and moves to the next 
        result set. If there were no result sets, a :exc:`ProgrammingError` is 
        raised.
    
    .. method:: fetchmany(size=self.arraysize)
        
        Fetch up to *size* rows. If there aren't that many rows available in 
        the result set, this returns as many as were available. If the result
        set was previously exhausted, this returns an empty list and moves to 
        the next result set. If there were no result sets, a 
        :exc:`ProgrammingError` is raised.
    
    .. method:: fetchall()
        
        Fetch all available rows from every result set. This will immediately 
        buffer all the results client-side. For large result sets, it can be 
        more performant to iterate over the cursor or use :meth:`fetchmany`. If 
        there were no result sets, a :exc:`ProgrammingError` is raised.
    
    .. attribute:: arraysize
        
        A nonzero positive integer which controls the default number of rows 
        returned when calling :meth:`fetchmany` with no arguments. The default 
        value is ``1``.
    
    .. attribute:: description
        
        As documented in :pep:`249`: a seven-tuple of ``(name, type_code, display_size, internal_size, precision, scale, null_ok)``.
    
    .. attribute:: lastrowid
        
        The rowid of the last inserted or updated row. For a full discussion of
        the semantics, see the documentation for the 
        :mysqlfunc:`mysql_insert_id` function.
        
        If :meth:`executemany` was called, *lastrowid* will reflect the rowid 
        for the last set of parameters that were passed.
    
    .. attribute:: rowcount
        
        The number of rows affected by the last query. This will not return the
        number of rows returned to a SELECT query. For a discussion of the
        semantics, see the documentation for the
        :mysqlfunc:`mysql_stmt_affected_rows` function. Also note that the
        *found_rows* parameter to :class:`Connection`, which controls the
        :c:data:`CLIENT_FOUND_ROWS` flag, defaults to ``True``.

:class:`DictCursor`
-------------------

.. class:: DictCursor

    :class:`DictCursor` instances represent rows as dicts mapping column names 
    or aliases to values. These key names are taken from the 
    :attr:`~oursql.Cursor.description` attribute of the cursor, and are 
    therefore affected by the ``show_table`` cursor option. A 
    :exc:`ProgrammingError` is raised when fetching a row if there were 
    duplicate keys with inequal values.

String streaming
================

:class:`IterWrapper`
--------------------

.. class:: IterWrapper(iterobj)
    
    :class:`IterWrapper` is a wrapper class for arbitrary string-yielding 
    iterable objects so that their contents can be streamed over the wire as a 
    bound parameter for a query. The strings are assumed to be text and not
    arbitrary bytes.

:class:`BinaryIterWrapper`
--------------------------

.. class:: BinaryIterWrapper
    
    :class:`BinaryIterWrapper` behaves like :class:`IterWrapper`, except the 
    strings yielded from the iterable are treated as bytes instead of text 
    strings.

:class:`FileWrapper`
--------------------

.. class:: FileWrapper(fileobj, chunksize=8192, doclose=False)
    
    :class:`FileWrapper` is a wrapper class for file-like objects so that their 
    contents can be streamed over the wire as a bound parameter for a query. 
    Strings read from the wrapped file are assumed to be text and not arbitrary 
    bytes.
    
    Strings will be read by calling the ``read()`` method on the file object 
    with *chunksize* as the only parameter parameter until it returns the empty 
    string. If *doclose* is true, the file will have its ``close()`` method 
    called once it has been exhausted.

:class:`BinaryFileWrapper`
--------------------------

.. class:: BinaryFileWrapper
    
    :class:`BinaryFileWrapper` behaves exactly like :class:`FileWrapper`, 
    except the strings yielded from the file object are treated as bytes 
    instead of text strings.

Exceptions
==========

.. data:: errnos

    A dict mapping MySQL error names to errnos, e.g. ``oursql.errnos['ER_ACCESS_DENIED_ERROR'] == 1045``.

Some exception descriptions are lovingly stolen from :pep:`249`.

:class:`Warning`
----------------

.. exception:: Warning(message)

    A :class:`Warning` represents a MySQL warning, which are generated from  
    problems that occur during queries, e.g. when data is truncated on insert 
    or in the wrong encoding.

:class:`Note`
-------------

.. exception:: Note

    A :class:`Note` is similar to a :class:`Warning`, but is less severe.

:class:`Error`
--------------

.. exception:: Error(message, errno=None, extra=None)

    This is the base class for all the oursql-defined error exceptions.
    
    .. attribute:: errno
    
        For errors originating from MySQL, this will be set to an integer 
        representing the exact MySQL errno. Errors originating from oursql will
        have an :attr:`errno` of ``None``. See also the :data:`errnos` dict.
    
    .. attribute:: extra
    
        Contains extra information about the error. This is currently only used
        by the :exc:`CollatedWarningsError` exception.

:class:`InterfaceError`
-----------------------

.. exception:: InterfaceError

    This exception represents errors that are related to the interface to the
    database instead of the database itself.

:class:`DatabaseError`
----------------------

.. exception:: DatabaseError

    This exception represents errors that are related to the database.

:class:`DataError`
------------------

.. exception:: DataError

    This exception represents errors that are due to problems with the 
    processed data like division by zero, numeric value out of range, etc.

:class:`OperationalError`
-------------------------

.. exception:: OperationalError

    This exception represents errors that are related to the database's 
    operation and not necessarily under the control of the programmer, e.g. an 
    unexpected disconnect occurs, the data source name is not found, a 
    transaction could not be processed, a memory allocation error occurred 
    during processing, etc.

:class:`IntegrityError`
-----------------------

.. exception:: IntegrityError

    This exception represents errors that are related to when the relational 
    integrity of the database is affected, e.g. a foreign key check fails.

:class:`InternalError`
----------------------

.. exception:: InternalError

    This exception represents errors that are related to when the database 
    encounters an internal error, e.g. the cursor is not valid anymore, the
    transaction is out of sync, etc. 

:class:`ProgrammingError`
-------------------------

.. exception:: ProgrammingError

    This exception represents programming errors, e.g. table not found or 
    already exists, syntax error in the SQL statement, wrong number of 
    parameters specified, etc.

:class:`CollatedWarningsError`
------------------------------

.. exception:: CollatedWarningsError

    This exception represents that one or more warnings were generated by 
    running a query, and have been collated all together.
    
    .. attribute:: extra
    
        A list of ``(type, (message, errno))`` tuples, where ``type`` is a 
        :exc:`Warning`, :exc:`Note`, or a subclass of :exc:`Error`.

:class:`NotSupportedError`
--------------------------

.. exception:: NotSupportedError

    This exception represents that the requested action is not supported by 
    either MySQL or oursql.

:class:`PermissionsError`
-------------------------

.. exception:: PermissionsError

    This exception represents that the current user did not have sufficient 
    permissions to perform the requested action.
