=========
Changelog
=========

0.9.2
=====
* Recategorized ``ER_DUP_ENTRY`` as an :exc:`~oursql.IntegrityError`.
* Made :class:`~oursql.Connection` objects usable as context managers, fixing
  #506821.
* Calling :mysqlfunc:`mysql_library_init` in ``initoursql`` to prevent 
  potential problems with multithreading.
* Fixed :class:`~oursql.IterWrapper` to call :func:`iter` on what it's passed,
  fixing #545104.

0.9.1
=====

* Fixed something that broke 2.5- compatibility.
* Fixed mingw support.
* Fixed the license in :file:`COPYING`.
* Added a distutils command to zip binary installers with a license file, for
  BSD license compliance.

0.9
===

* Fixed a bug in :meth:`~oursql.Connection._escape_string` and 
  :meth:`~oursql.Connection._escape_unicode_string` when called with 0-length
  strings.
* Fixed FreeBSD support in :file:`pstdint.h`.
* Worked around a setuptools bug in :file:`setup.py`.
* Added support for :envvar:`MYSQL_CONFIG`.
* Added many more parameters for :func:`oursql.connect`.
* Mapped more MySQL errors to oursql exceptions.
* Added :data:`oursql.errnos`.
