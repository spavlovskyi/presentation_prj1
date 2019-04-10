#!/bin/bash

set -ex
cd "${BASH_SOURCE%/*}"
config=${1:-Default}
builddir=out/$config
[[
	configure.sh -nt $builddir/build.ninja
	|| config-$config.sh -nt $builddir/build.ninja
	|| conanfile.txt -nt $builddir/conaninfo.txt
]] && ./configure.sh $config
cd $builddir
PKG_CONFIG_PATH=$PWD exec ninja -v test install
