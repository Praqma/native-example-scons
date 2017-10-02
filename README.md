# Build with SCons

[![CircleCI](https://circleci.com/gh/Praqma/native-example-scons.png?style=shield&circle-token=df3dc5f6efbc2a267f7805f05a5e91d2878be9fd)](https://circleci.com/gh/Praqma/native-example-scons)
[![TravisCI Status](https://travis-ci.org/Praqma/native-example-scons.svg?branch=master)](https://travis-ci.org/Praqma/native-example-scons)

![](https://img.shields.io/github/stars/praqma/native-example-scons.svg)
![](https://img.shields.io/github/forks/praqma/native-example-scons.svg)
![](https://img.shields.io/github/watchers/praqma/native-example-scons.svg)
![](https://img.shields.io/github/tag/praqma/native-example-scons.svg)
![](https://img.shields.io/github/release/praqma/native-example-scons.svg)
![](https://img.shields.io/github/issues/praqma/native-example-scons.svg)

Building with [SCons](http://scons.org/).

See [native](https://github.com/Praqma/native) repository for more examples.

## Steps

* Build image: `./dockerize.sh`
* Run container: `./containerize.sh`
* Build example (inside container): `./build.sh`
* Test example (inside container): `./test.sh`

## Documentation

* Construction Variables

```
 CFLAGS
 http://scons.org/doc/production/HTML/scons-man.htmlcv-CFLAGS
 General options that are passed to the C compiler (C only; not C++).

 CCFLAGS
 http://scons.org/doc/production/HTML/scons-man.htmlcv-CCFLAGS
 General options that are passed to the C and C++ compilers.

 CXXFLAGS
 http://scons.org/doc/production/HTML/scons-man.htmlcv-CXXFLAGS
 General options that are passed to the C++ compiler.
 By default, this includes the value of $CCFLAGS, so that setting
   $CCFLAGS affects both C and C++ compilation.
 If you want to add C++-specific flags, you must set or override the
   value of $CXXFLAGS.

 CPPPATH
 http://scons.org/doc/production/HTML/scons-man.htmlcv-CPPPATH
 The list of directories that the C preprocessor will search for
   include directories.
 The C/C++ implicit dependency scanner will search these directories
   for include files.
 Don't explicitly put include directory arguments in CCFLAGS or
   CXXFLAGS because the result will be non-portable and the directories
 will not be searched by the dependency scanner.
 Note: directory names in CPPPATH will be looked-up relative to the
   SConscript directory when they are used in a command.
```

* Construction Variables and Environments in SCons

```
 C and C++ Compiling
 http://pages.cs.wisc.edu/~driscoll/software/scons/variables.html

 CCFLAGS: you've already seen this, of course. It is passed as part of
   the command line for compiling C and C++ files.
 CFLAGS, CXXFLAGS: flags passed to the C compiler (but not C++
   compiler) and vice versa, respectively.
 CPPDEFINES: a collection of preprocessor definition flags. It can be
   a single string, a list, or a dictionary.
 For the dictionary, it should have a form similar to
   {'FOO' : 'foo', 'BAR' : None} which will get translated to the flags
   -DBAR -DFOO=foo or /DBAR /DFOO=foo depending on the compiler.
   (Lists and strings are similar; see the SCons docs.)
 CPPPATH: a list of directories that should be searched for include
   files (both by the compiler, via the -I flag or similar, and by
   SCons when scanning implicit dependencies).
 CC, CXX: the C and C++ compiler to use

 Linking

 LINKFLAGS: flags to pass to the linker
 RPATH: a list of directories to -Wl,-rpath into the program; using
  this requires not overwriting $LINKFLAGS completely.
 LIBPATH: a list of directories that should be search for libraries
  (both by the linker, via the -L flag or similar, and by SCons when
  scanning for changes).
 LIBS: a list of libraries to link against (gets translated to a series
  of -l flags to GCC). Don't include the lib prefix on Linux or .so or
  .lib suffix.
 LINK: the name of the linker
```

## Lesson Learned

1. Two Environments With Different Actions Were Specified For The Same Target

* If you use the below two lines together in a `SConstruct` file, the build would fail.

```
release_env.SharedLibrary(target = 'mathy', source = [os.path.join(project_dir,"src","mathy.cc")])

debug_env.SharedLibrary(target = 'mathy', source = [os.path.join(project_dir,"src","mathy.cc")])
```

* Error
```
scons: *** Two environments with different actions were specified for the same target: omed-app/src/mathy.os
(action 1: g++ -o mathy.os -c -Wall -Werror -std=c++11 -O2 -fPIC -DRELEASE mathy.cc)
(action 2: g++ -o mathy.os -c -Wall -Werror -std=c++11 -g -fPIC -DDEBUG mathy.cc)
File "/Users/leonard/github/omed-scons/SConstruct", line 184, in <module>
```

* Workaround
```
release_mathy_os = release_env.SharedObject(os.path.join(out_obj_dir,'mathy.os'), [os.path.join(project_dir,"src","mathy.cc")])
release_env.SharedLibrary(os.path.join(out_lib_dir,'mathy'), release_mathy_os)

debug_mathy_os = debug_env.SharedObject(os.path.join(out_obj_dir,'mathyd.os'), [os.path.join(project_dir,"src","mathy.cc")])
debug_env.SharedLibrary(os.path.join(out_lib_dir,'mathyd'), debug_mathy_os)
```
