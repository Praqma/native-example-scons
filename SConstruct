import os

env = Environment()

# # Uncomment the below section to print all the Construction Variables.
# ######################################################################
# print ""
# print "env.Dump('CC'):", env.Dump('CC')
# print "env.subst('$CC'):", env.subst('$CC')
# print "env.Dump('CCCOM'):", env.Dump('CCCOM')
# print "env.Dump('CFLAGS'):", env.Dump('CFLAGS')
# print "env.Dump('CCVERSION'):", env.Dump('CCVERSION')
# print ""
# print "env.Dump('CCFLAGS'):", env.Dump('CCFLAGS')
# print ""
# print "env.Dump('CXX'):", env.Dump('CXX')
# print "env.subst('$CXX'):", env.subst('$CXX')
# print "env.Dump('CXXCOM'):", env.Dump('CXXCOM')
# print "env.Dump('CXXFLAGS'):", env.Dump('CXXFLAGS')
# print "env.Dump('CXXVERSION'):", env.Dump('CXXVERSION')
# print ""
# env = Environment()
# dict = env.Dictionary()
# keys = dict.keys()
# keys.sort()
# for key in keys:
# 	print "SConstruct Variable \t = '%s', \n SConstruct Value = '%s'" \
# 	% (key, dict[key])
# print ""
# ######################################################################

print "os.getcwd(): ", os.getcwd()
project_dir = os.path.join(os.getcwd(),'omed-app')
output_dir = os.path.join(os.getcwd(),'out')

# Set our required libraries
libraries 		= []
library_paths 	= [output_dir, os.path.join(output_dir,'lib')]  # ['/usr/lib', '/usr/local/lib']
include_paths 	= [project_dir, os.path.join(project_dir,'inc')]
cppDefines 		= {}
cppFlags 		= ['-Wall', '-Werror']
cxxFlags 		= ['-std=c++11']

# define the attributes of the build environment shared between
# both the debug and release builds
environment = Environment()
environment.Append(LIBS = libraries)
environment.Append(LIBPATH = library_paths)
environment.Append(CPPDEFINES = cppDefines)
environment.Append(CFLAGS = cppFlags)
environment.Append(CCFLAGS = cppFlags)
environment.AppendUnique(CCFLAGS = cppFlags)
environment.AppendUnique(CCFLAGS = [
									'-std=c++11',
									'-Werror',
									'-Wall'
									# '-Wextra',
									# '-Warray-bounds',
									# '-Weffc++',
									# '-Wno-parentheses',
									# '-Wpedantic',
									# '-Wwrite-strings'
									] )
environment.AppendUnique(CPPPATH = include_paths)


print ""
print "environment.Dump('CC'):", environment.Dump('CC')
print "environment.Dump('CCCOM'):", environment.Dump('CCCOM')
print "environment.Dump('CFLAGS'):", environment.Dump('CFLAGS')
print "environment.Dump('CCVERSION'):", environment.Dump('CCVERSION')
print ""
print "environment.Dump('CCFLAGS'):", environment.Dump('CCFLAGS')
print ""
print "environment.Dump('CXX'):", environment.Dump('CXX')
print "environment.Dump('CXXCOM'):", environment.Dump('CXXCOM')
print "environment.Dump('CXXFLAGS'):", environment.Dump('CXXFLAGS')
print "environment.Dump('CXXVERSION'):", environment.Dump('CXXVERSION')
print ""
print ""

out_bin_dir = output_dir+os.sep+'bin'
out_lib_dir = output_dir+os.sep+'lib'
out_obj_dir = output_dir+os.sep+'obj'

for directory_name in [out_bin_dir, out_bin_dir, out_obj_dir]:
	if Execute(Mkdir(directory_name)):
		Exit(1) # Cannot make the directory.

# # Our release build is derived from the common build environment...
release_env = environment.Clone()
release_env.AppendUnique(CPPDEFINES = ['RELEASE'])
release_env.AppendUnique(CCFLAGS = ['-O2'])
release_env.VariantDir('out/release', project_dir, duplicate=0)

# release_env.StaticLibrary(target = 'mathy', source = [os.path.join(project_dir,"src","mathy.cc")])
release_mathy_o = release_env.StaticObject(os.path.join(out_obj_dir,'mathy.o'), [os.path.join(project_dir,"src","mathy.cc")])
release_env.StaticLibrary(os.path.join(out_lib_dir,'mathy'), release_mathy_o)
# release_env.SharedLibrary(target = 'mathy', source = [os.path.join(project_dir,"src","mathy.cc")])
release_mathy_os = release_env.SharedObject(os.path.join(out_obj_dir,'mathy.os'), [os.path.join(project_dir,"src","mathy.cc")])
release_env.SharedLibrary(os.path.join(out_lib_dir,'mathy'), release_mathy_os)

release_obj = release_env.Object(os.path.join(out_obj_dir,'main.o'), [os.path.join(project_dir,"src","main.cc")])
release_env.Program(target = os.path.join(out_bin_dir,'main'), source = [release_obj, release_mathy_o])

# # We define our debug build environment in a similar fashion...
debug_env = environment.Clone()
debug_env.AppendUnique(CPPDEFINES = ['DEBUG'])
debug_env.AppendUnique(CCFLAGS = ['-g'])
debug_env.VariantDir('out/debug', project_dir, duplicate=0)

# debug_env.StaticLibrary(target = 'mathy', source = [os.path.join(project_dir,"src","mathy.cc")])
debug_mathy_o = debug_env.StaticObject(os.path.join(out_obj_dir,'mathyd.o'), [os.path.join(project_dir,"src","mathy.cc")])
debug_env.StaticLibrary(os.path.join(out_lib_dir,'mathyd'), debug_mathy_o)
# debug_env.SharedLibrary(target = 'mathy', source = [os.path.join(project_dir,"src","mathy.cc")])
debug_mathy_os = debug_env.SharedObject(os.path.join(out_obj_dir,'mathyd.os'), [os.path.join(project_dir,"src","mathy.cc")])
debug_env.SharedLibrary(os.path.join(out_lib_dir,'mathyd'), debug_mathy_os)

debug_obj = debug_env.Object(os.path.join(out_obj_dir,'maind.o'), [os.path.join(project_dir,"src","main.cc")])
debug_env.Program(target = os.path.join(out_bin_dir,'maind'), source = [debug_obj, debug_mathy_o])



# ######################################################################
# # Explanation of Some Construction Variables
#
# CFLAGS
# http://scons.org/doc/production/HTML/scons-man.html#cv-CFLAGS
# General options that are passed to the C compiler (C only; not C++).
#
# CCFLAGS
# http://scons.org/doc/production/HTML/scons-man.html#cv-CCFLAGS
# General options that are passed to the C and C++ compilers.
#
# CXXFLAGS
# http://scons.org/doc/production/HTML/scons-man.html#cv-CXXFLAGS
# General options that are passed to the C++ compiler.
# By default, this includes the value of $CCFLAGS, so that setting
#   $CCFLAGS affects both C and C++ compilation.
# If you want to add C++-specific flags, you must set or override the
#   value of $CXXFLAGS.
#
# CPPPATH
# http://scons.org/doc/production/HTML/scons-man.html#cv-CPPPATH
# The list of directories that the C preprocessor will search for
#   include directories.
# The C/C++ implicit dependency scanner will search these directories
#   for include files.
# Don't explicitly put include directory arguments in CCFLAGS or
#   CXXFLAGS because the result will be non-portable and the directories
# will not be searched by the dependency scanner.
# Note: directory names in CPPPATH will be looked-up relative to the
#   SConscript directory when they are used in a command.
# ######################################################################

# ######################################################################
# # Construction Variables and Environments in SCons
# http://pages.cs.wisc.edu/~driscoll/software/scons/variables.html
#
# C and C++ Compiling
#
# CCFLAGS: you've already seen this, of course. It is passed as part of
#   the command line for compiling C and C++ files.
# CFLAGS, CXXFLAGS: flags passed to the C compiler (but not C++
#   compiler) and vice versa, respectively.
# CPPDEFINES: a collection of preprocessor definition flags. It can be
#   a single string, a list, or a dictionary.
# For the dictionary, it should have a form similar to
#   {'FOO' : 'foo', 'BAR' : None} which will get translated to the flags
#   -DBAR -DFOO=foo or /DBAR /DFOO=foo depending on the compiler.
#   (Lists and strings are similar; see the SCons docs.)
# CPPPATH: a list of directories that should be searched for include
#   files (both by the compiler, via the -I flag or similar, and by
#   SCons when scanning implicit dependencies).
# CC, CXX: the C and C++ compiler to use
#
# Linking
#
# LINKFLAGS: flags to pass to the linker
# RPATH: a list of directories to -Wl,-rpath into the program; using
#  this requires not overwriting $LINKFLAGS completely.
# LIBPATH: a list of directories that should be search for libraries
#  (both by the linker, via the -L flag or similar, and by SCons when
#  scanning for changes).
# LIBS: a list of libraries to link against (gets translated to a series
#  of -l flags to GCC). Don't include the lib prefix on Linux or .so or
#  .lib suffix.
# LINK: the name of the linker
# ######################################################################