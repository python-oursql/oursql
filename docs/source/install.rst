============
Installation
============

Installing oursql is mostly like installing any other python package. It's 
strongly recommended to use your platform's package manager if there is a 
package for oursql, a binary release from launchpad if not, and only to compile 
from source if nothing else is available.

Requirements
============

oursql requires python 2.4 or better, and MySQL 4.1.2 or better.

Only the `MySQL C client libraries 
<http://dev.mysql.com/downloads/connector/c/>`_ are required for oursql. These 
libraries are available separately if it's not essential to download/install 
the entire MySQL package.

Using pip
=========

On systems where there is a :command:`mysql_config` command, using pip is 
trivial::

    pip install oursql

If :command:`mysql_config` is not named :command:`mysql_config`, the 
environment can be set to indicate the actual name::

    MYSQL_CONFIG=mysql_config5 pip install oursql

If there is no :command:`mysql_config`, you must determine the necessary 
:envvar:`CFLAGS` and :envvar:`LDFLAGS` yourself and pass them to pip.

Getting oursql
==============

The newest release of oursql will always be available on its project site on
launchpad: https://launchpad.net/oursql.

Installing from source
----------------------

On systems where there is a :command:`mysql_config` command, using distutils is 
also trivial::

    python setup.py build_ext
    python setup.py install

If :command:`mysql_config` is not named :command:`mysql_config`, you can tell 
``build_ext`` to try a different name using command-line flags or environment 
variables::

    python setup.py build_ext --mysql-config=mysql_config5
    # (or!)
    MYSQL_CONFIG=mysql_config5 python setup.py build_ext
    python setup.py install

On Windows, :file:`setup.py` will try checking the registry to determine what 
the path to your MySQL installation is. By default, it will only check for an 
installation of MySQL 5.0. An alternate registry key or MySQL installation root
can be passed to ``build_ext``::

    python setup.py build_ext "--mysql-registry-key=SOFTWARE\MySQL AB\MySQL Server 5.1"
    python setup.py install

    python setup.py build_ext "--mysql-root=C:\Program Files\MySQL\MySQL Server 5.1"
    python setup.py install
