from distutils.cmd import Command
from distutils.core import setup
from distutils.util import split_quoted
from distutils.extension import Extension
from distutils.msvccompiler import MSVCCompiler
from distutils.command.build_ext import build_ext
import subprocess
import zipfile
import os

try:
    import winreg
except ImportError:
    winreg = None

class MysqlExtension(Extension):
    def __init__(self, *a, **kw):
        self.use_mysql_flags = True
        self._extra_compile_args = []
        self._extra_link_args = []
        self._mysql_compile_args = []
        self._mysql_link_args = []
        self.get_mysql_compile_args = self.get_mysql_link_args = None
        Extension.__init__(self, *a, **kw)
    
    def _get_extra_compile_args(self):
        if not self._mysql_compile_args and self.get_mysql_compile_args:
            self._mysql_compile_args = self.get_mysql_compile_args()
        return self._extra_compile_args + self._mysql_compile_args
    
    def _set_extra_compile_args(self, args):
        self._extra_compile_args = args
    
    extra_compile_args = property(
        _get_extra_compile_args, _set_extra_compile_args)
    
    def _get_extra_link_args(self):
        if not self._mysql_link_args and self.get_mysql_link_args:
            self._mysql_link_args = self.get_mysql_link_args()
        return self._extra_link_args + self._mysql_link_args
    
    def _set_extra_link_args(self, args):
        self._extra_link_args = args
    
    extra_link_args = property(_get_extra_link_args, _set_extra_link_args)

oursql_ext = MysqlExtension("oursql", ["oursqlx/compat.c"])

try:
    from Cython.Distutils import build_ext
except ImportError:
    print("cython not found, using previously-cython'd .c file.")
    oursql_ext.sources.insert(0, 'oursqlx/oursql.c')
else:
    oursql_ext.sources.insert(0, 'oursqlx/oursql.pyx')

oursql_commands = {}

class oursql_build_ext(build_ext):
    user_options = build_ext.user_options + [
        ('mysql-config=', None, 
            '(*nix only) path to the mysql-config executable'),
        ('use-libmysqld', None,
            '(*nix only) link against libmysqld instead of libmysqlclient'),
        ('static', None,
            '(Windows only) statically link against mysqlclient.lib'),
        ('mysql-registry-key=', None,
            '(Windows only) the registry key to query for the mysql root '
            'directory'),
        ('mysql-root=', None,
            '(Windows only) the path to the mysql installation; can be given '
            'instead of --mysql-registry-key'),
    ]
    
    boolean_options = build_ext.boolean_options + [
        'use-libmysqld', 'static'
    ]
    
    def initialize_options(self):
        build_ext.initialize_options(self)
        self.mysql_config = os.environ.get('MYSQL_CONFIG', 'mysql_config')
        self.use_libmysqld = self.static = 0
        self.mysql_registry_key = r'SOFTWARE\MySQL AB\MySQL Server 5.0'
        self.mysql_root = None
    
    def get_mysql_config(self, option):
        args = [self.mysql_config, '--%s' % option]
        print(' '.join(args))
        try:
            proc = subprocess.Popen(args, stdout=subprocess.PIPE)
        except:
            print('failed to execute', args[0])
            raise
        stdout, _ = proc.communicate()
        return split_quoted(stdout.strip().decode())
    
    def setup_posixish(self, ext):
        ext.get_mysql_compile_args = (
            lambda: self.get_mysql_config('cflags'))
        if self.use_libmysqld:
            ext.get_mysql_link_args = (
                lambda: self.get_mysql_config('libmysqld-libs'))
        else:
            ext.get_mysql_link_args = (
                lambda: self.get_mysql_config('libs'))
    
    def setup_windowsish(self, ext):
        if self.mysql_root:
            mysql_root = self.mysql_root
        else:
            mysql_key = winreg.OpenKey(
                winreg.HKEY_LOCAL_MACHINE, self.mysql_registry_key)
            mysql_root, _ = winreg.QueryValueEx(mysql_key, 'Location')
        
        if self.static:
            client = "mysqlclient"
        else:
            client = "libmysql"

        ext.library_dirs.append(
            os.path.join(mysql_root, 'lib', 'opt'))
        ext.libraries.extend(['advapi32', 'wsock32', client])
        ext.include_dirs.append(
            os.path.join(mysql_root, 'include'))
        if isinstance(self.compiler, MSVCCompiler):
            if self.static:
                ext.get_mysql_compile_args = lambda: ['/MT']
            else:
                ext.get_mysql_compile_args = lambda: ['/MD']

    
    def build_extension(self, ext):
        if getattr(ext, 'use_mysql_flags', False):
            try:
                # distribute/setuptools flip out if I try to open(os.devnull),
                # so, I work around their stupidity by using a pipe instead.
                proc = subprocess.Popen([self.mysql_config], 
                    stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
            except OSError:
                if winreg:
                    self.setup_windowsish(ext)
                else:
                    print('warning: no usable mysql_config and no winreg '
                        'module to try; hopefully you have usable '
                        'CFLAGS/LDFLAGS set.')
            else:
                proc.communicate()
                self.setup_posixish(ext)
        build_ext.build_extension(self, ext)
oursql_commands['build_ext'] = oursql_build_ext

try:
    from distutils.command.bdist_msi import bdist_msi
except ImportError:
    pass
else:
    class oursql_bdist_msi(bdist_msi):
        def run(self):
            bdist_msi.run(self)
            if hasattr(self.distribution, 'dist_files'):
                command, pyversion, filename = (
                    self.distribution.dist_files.pop())
                filename = self.get_installer_filename(filename)
                self.distribution.dist_files.append(
                    (command, pyversion, filename))
    oursql_commands['bdist_msi'] = oursql_bdist_msi

class ZipWithLicense(Command):
    description = 'zip binary installer with the license'
    user_options = []
    boolean_options = []
    
    def initialize_options(self):
        pass
    
    def finalize_options(self):
        pass
    
    def run(self):
        license = open(os.path.join(
            os.path.dirname(os.path.abspath(__file__)), 'COPYING')).read()
        license = '\r\n'.join(license.splitlines())
        fullname = self.distribution.get_fullname()
        
        dist_files = getattr(self.distribution, 'dist_files', None)
        if dist_files is None:
            dist_files = []
            for command, cmd_obj in self.distribution.command_obj.iteritems():
                if command.startswith('bdist_'):
                    dist_files.append(
                        (None, None, cmd_obj.get_installer_filename(fullname)))
        
        new_dist_files = []
        for command, pyversion, filename in dist_files:
            out_filename = os.path.splitext(filename)[0] + '.zip'
            out_file = zipfile.ZipFile(out_filename, 'w')
            out_file.write(filename, '%s/%s' % (
                fullname, os.path.basename(filename)))
            out_file.writestr('%s/LICENSE.txt' % fullname, license)
            out_file.close()
            new_dist_files.append((command, pyversion, out_filename))
        self.distribution.dist_files = new_dist_files
oursql_commands['zipwithlicense'] = ZipWithLicense

setup(
    name='oursql3',
    version='0.9.4',
    author='Aaron Gallagher',
    author_email='habnabit@gmail.com',
    url='http://launchpad.net/oursql',
    description='MySQL bindings for python.',
    long_description="""
        oursql is a set of MySQL bindings for python 2.4+ with a focus on 
        wrapping the `MYSQL_STMT API`__ to provide real parameterization and 
        real server-side cursors. MySQL 4.1.2 or better is required.
        
        __ http://dev.mysql.com/doc/refman/5.0/en/c-api-prepared-statements.html
        
        There's extensive documentation available online at 
        http://packages.python.org/oursql/.
    """,
    classifiers=[
        'Development Status :: 4 - Beta',
        'License :: OSI Approved :: BSD License',
        'Operating System :: OS Independent',
        'Programming Language :: C',
        'Programming Language :: Cython',
        'Programming Language :: Python :: 3',
        'Topic :: Database :: Database Engines/Servers',
    ],
    
    ext_modules=[oursql_ext],
    cmdclass=oursql_commands,
)
