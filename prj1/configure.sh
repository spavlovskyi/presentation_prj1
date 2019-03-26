#!/bin/bash

set -ex
config=${1:-Default}
. config-$config.sh
builddir=out/$config
mkdir -p $builddir
cd $builddir
rm -rf meson-private
exec meson setup --buildtype=$meson_buildtype ../..
