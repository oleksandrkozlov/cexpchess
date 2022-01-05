cexpchess
=========

[![Build Status](https://travis-ci.com/oleksandrkozlov/cexpchess.svg?branch=master)](https://travis-ci.com/oleksandrkozlov/cexpchess)
[![Coverage Status](https://codecov.io/gh/oleksandrkozlov/cexpchess/branch/master/graph/badge.svg)](https://codecov.io/gh/oleksandrkozlov/cexpchess)
[![Coverity Status](https://scan.coverity.com/projects/22300/badge.svg)](https://scan.coverity.com/projects/oleksandrkozlov-cexpchess)

### Configure

```
CC=clang CXX=clang++ cmake -Bbuild -H. -DCMAKE_BUILD_TYPE=Debug
```

### Build

```
cmake --build build
```

### Test

```
cmake --build build --target test
```

### Install

```
cmake --install build
```

### Run

```
cexpchess
```

### Dependencies

* [CMake](https://cmake.org) >= 3.16
* [GSL](https://github.com/microsoft/GSL) >= 3.1
* [docopt.cpp](https://github.com/docopt/docopt.cpp) >= 0.6
* [pkg-config](https://www.freedesktop.org/wiki/Software/pkg-config/) >= 0.29
* [spdlog](https://github.com/gabime/spdlog) >= 1.5
* [{fmt}](https://fmt.dev/) >= 6.1

### Development Dependencies

* [Clang-Tidy](https://releases.llvm.org/10.0.0/tools/clang/tools/extra/docs/clang-tidy/) >= 10.0
* [ClangFormat](https://releases.llvm.org/10.0.0/tools/clang/docs/ClangFormat.html) >= 10.0
* [Conventional Commits](https://www.conventionalcommits.org) >= 1.0
* [Cppcheck](http://cppcheck.sourceforge.net) >= 1.90
* [Google Test](https://github.com/google/googletest) >= 1.10
* [Kcov](http://simonkagstrom.github.io/kcov/) >= 38.0
* [Ninja](https://ninja-build.org) >= 1.10
* [Python](https://www.python.org) >= 3.8
* [ccache](https://ccache.dev) >= 3.7
* [cmake language tools](https://cmake-format.readthedocs.io) >= 0.6
* [include-what-you-use](https://include-what-you-use.org) >= 0.13

### Continuous Integration Dependencies

* [Bundler](https://bundler.io) >= 2.1
* [Codecov](https://codecov.io)
* [Danger](https://danger.systems/ruby) >= 8.0
* [Docker](https://www.docker.com) > 18.6
* [Git](https://git-scm.com) >= 2.25
* [Node.js](https://nodejs.org) >= 8.12
* [Ruby](https://www.ruby-lang.org) >= 2.5
* [commitlint](https://commitlint.js.org) >= 8.3
* [curl](https://curl.haxx.se) >= 7.68
* [nmp](https://www.npmjs.com) >= 6.14

### License

[MIT License](https://github.com/oleksandrkozlov/cexpchess/blob/master/LICENSE), Copyright (c) 2022 Oleksandr Kozlov
