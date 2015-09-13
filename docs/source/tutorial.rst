========
Tutorial
========

Since oursql implements the DB-API, the basics of how to use it should be
straightforward and explained in detail in other documents. This tutorial will
thus mostly focus on behavior that is specific to oursql.

Establishing a connection
=========================

To make a connection, there's the :func:`oursql.connect` function::

    conn = oursql.connect(host='127.0.0.1', user='habnabit', passwd='foobar', 
        db='example', port=3307)

.. _unicode_support:

By default, oursql will try to use unicode wherever possible, and set the 
connection charset to utf8. To use the database's default connection charset,
pass a *charset* of ``None``::

    conn = oursql.connect(db='example', charset=None)

It's sometimes necessary to disable unicode handling, such as if there is 
malformed data in the database and not every row can be decoded using the same
encoding. oursql has the option of completely ignoring unicode::

    conn = oursql.connect(db='example', use_unicode=False, charset=None)

Using cursors
=============

Cursors are created by calling the :meth:`~oursql.Connection.cursor` method on
a connection. This method also allows specification of the cursor class and 
other extra options for the cursor::

    curs = conn.cursor(oursql.DictCursor)
    curs = conn.cursor(try_plain_query=False)

The available cursor options are also documented on the 
:meth:`~oursql.Connection.cursor` method.

.. _parameterization:

Executing queries
-----------------

oursql uses the ``qmark`` parameterization style; placeholders in queries are
represented using a single question mark::

    curs.execute(
        'SELECT * FROM `some_table` WHERE `col1` = ? AND `col2` = ?',
        (42, -3))

Queries and data are sent to the database server completely separately, 
alleviating the need for escaping data.

Inserting large data sets
-------------------------

.. _string_streaming_in:

oursql also provides a number of ways to insert large amounts of data without
buffering it all in memory. For inserting long string values, there's 
:class:`~oursql.IterWrapper` and :class:`~oursql.FileWrapper`, and for long 
binary values, there's :class:`~oursql.BinaryIterWrapper` and 
:class:`~oursql.BinaryFileWrapper`. Usage is very straightforward::

    iw = oursql.IterWrapper([u'foo', u'bar'])
    fw = oursql.FileWrapper(codecs.open('some_file.txt', encoding='utf8'))
    biw = oursql.BinaryIterWrapper(['spam', 'eggs'])
    bfw = oursql.BinaryFileWrapper(open('some_blob.txt', 'rb'))
    curs.execute(
        'INSERT INTO `some_table` VALUES (?, ?, ?, ?)',
        (iw, fw, biw, bfw))

Instances of these types will cause oursql to insert the data pieces at a time
instead of all at once, buffering server-side instead of client-side. 

.. _row_streaming_in:

Additionally, :meth:`~oursql.Cursor.executemany` is lazy; if passed a generator
or any other iterator which does produces values lazily, values will only be
taken from the iterator immediately before they are sent to the database.

Retrieving large data sets
--------------------------

.. _row_streaming_out:

By default, oursql will not buffer the results of a query client-side. The only
times oursql will ever buffer results client-side are:

1) If :meth:`~oursql.Cursor.execute` is called on the cursor with 
   ``plain_query=True``.
2) If :meth:`~oursql.Cursor.fetchall` is called on the cursor.
3) MySQL is below version 5.0.2 (see :mysqlfunc:`mysql_stmt_attr_set`).

.. _string_streaming_out:

Using the *string_limit* cursor option, oursql also provides a way to fetch 
long string or binary data from the database as needed instead of requiring an 
entire row to be buffered in memory::

    curs = conn.cursor(string_limit=8192)

If *string_limit* is not ``None``, oursql will return a file-like object in 
place of a string for any string or binary column. If the length of the data in 
the column is less than or equal to the *string_limit*, the data will be 
buffered client-side. Otherwise, all data will only be fetched from the 
database as requested. However, there are some caveats:

1) If :meth:`~oursql.Cursor.execute` is called on the cursor with 
   ``plain_query=True``, the *string_limit* will not be respected and all
   columns will come back as strings instead of file-like objects.
2) The file-like object provided must be used immediately. Fetching another
   row from the same cursor will invalidate any previously-fetched file-like 
   objects.
3) These objects only implement a ``read()`` method that takes one or no 
   arguments; seeking is not allowed, and there is no way to read only a single 
   line.
4) Data that is less than 66 bytes long will always be buffered client-side.

Working with binary columns
---------------------------

To ensure a clear separation between text and binary data, oursql requires that
binary data being inserted into the database be wrapped in a :class:`buffer`.
Turning a bytestring into a :class:`buffer` is a cheap operation and does not 
involve any copying::

    some_binary_data = '\xde\xad\xbe\xef'
    curs.execute('INSERT INTO `some_table` VALUES (?)', 
        (buffer(some_binary_data),))

Binary data coming back from the database will be of type :class:`str`.

Warnings and errors
===================

oursql implements the standard hierarchy of DB-API exceptions (see :pep:`249`), 
as well as :exc:`~oursql.PermissionsError` (which should be self-explanatory) 
and :exc:`~oursql.CollatedWarningsError`. Unless *raise_on_warnings* is 
explicitly turned off when calling :func:`oursql.connect`, any warnings or 
errors generated by running a query will be collected together and raised as a 
:exc:`~oursql.CollatedWarningsError`. A list of ``(type, (message, errno))``
tuples will be accessible as the :attr:`~oursql.CollatedWarningsError.extra`
attribute, where *type* is an oursql exception class.

A dict mapping MySQL error names to errnos is also exposed as 
:data:`oursql.errnos` for more easily trapping specific errors.

Use with ORMs
=============

* SQLAlchemy_ provides support for oursql in 
  version 0.6 and up.
* Django_ supports oursql via the django-oursql_ package.

.. _SQLAlchemy: http://www.sqlalchemy.org/
.. _Django: http://www.djangoproject.com/
.. _django-oursql: http://pypi.python.org/pypi/django-oursql
