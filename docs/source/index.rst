Welcome to oursql's documentation!
==================================

oursql_ is a new set of MySQL_ bindings for python 2.4+, including python 3.x. 
Here's a short list of reasons why you should use oursql over MySQLdb:

.. _oursql: http://launchpad.net/oursql
.. _MySQL: http://mysql.com/

* oursql has :ref:`real parameterization <parameterization>`, sending the SQL 
  and data to MySQL completely separately.
* oursql allows text or binary data to be :ref:`streamed into the database 
  <string_streaming_in>` and :ref:`streamed out of the database 
  <string_streaming_out>`, instead of requiring everything to be buffered in
  the client.
* oursql can both :ref:`insert rows lazily <row_streaming_in>` and :ref:`fetch 
  rows lazily <row_streaming_out>`.
* oursql :ref:`has unicode support on by default <unicode_support>`.
* oursql supports python 2.4 through 2.7 without any deprecation warnings on 
  2.6+ (see :pep:`218`) and without completely failing on 2.7 (see :pep:`328`).
* oursql runs natively on python 3.x.
* oursql is licensed under the `BSD license 
  <http://www.opensource.org/licenses/bsd-license.php>`_.

Anyone encountering bugs or any unexpected behavior in oursql should (please!) 
`post a bug report on the launchpad site <https://bugs.launchpad.net/oursql>`_. 

.. toctree::
	
	changelog.rst
	install.rst
	tutorial.rst
	api.rst
