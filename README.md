# swatch - a collection of Internet Time conversion scripts

Herein lies a collection of modulinos/applications in various programming languages for converting and displaying time in [Swatch beats](http://en.wikipedia.org/wiki/Swatch_Internet_Time).

# EXAMPLE

```console
$ cd c
$ cmake . && make
bin/swatch
@156.32
```

# REQUIREMENTS

## Compiler Collection

* [clang](http://clang.llvm.org/)

E.g. from Xcode

* [gcc](https://gcc.gnu.org/)

E.g. from Apt, Dnf, Homebrew, MinGW, Strawberry Perl

## CMake

* [cmake](https://cmake.org/)

E.g. `brew install cmake`

## Optional

* [make](https://www.gnu.org/software/make/)
* [GNU findutils](https://www.gnu.org/software/findutils/)
* [stank](https://github.com/mcandre/stank) (e.g. `go get github.com/mcandre/stank/...`)
* [Python](https://www.python.org) 3+ (for yamllint)
* [Node.js](https://nodejs.org/en/) (for eclint)
