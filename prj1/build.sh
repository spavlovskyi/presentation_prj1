#!/bin/bash

set -ex
cd "${BASH_SOURCE%/*}"
builddir=out
[[ configure.sh -nt $builddir/build.ninja ]] && ./configure.sh
cd $builddir
exec ninja -v
