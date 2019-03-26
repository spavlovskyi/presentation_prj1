#!/bin/bash

set -ex
config=${1:-Default}
. config-$config.sh
builddir=out/$config
mkdir -p $builddir
cd $builddir
conan install ../.. --build=missing -s build_type=$conan_buildtype -s compiler.libcxx=libstdc++11
rm -rf meson-private
PKG_CONFIG_PATH=$PWD exec meson setup --buildtype=$meson_buildtype ../..
