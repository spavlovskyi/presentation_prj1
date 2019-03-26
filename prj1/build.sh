#!/bin/bash

set -ex
cd "${BASH_SOURCE%/*}"
config=${1:-Default}
builddir=out/$config
[[
	configure.sh -nt $builddir/build.ninja
	|| config-$config.sh -nt $builddir/build.ninja
]] && ./configure.sh $config
cd $builddir
exec ninja -v
