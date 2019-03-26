#!/bin/bash

set -ex
meson_buildtype=debug
builddir=out
mkdir -p $builddir
cd $builddir
rm -rf meson-private
exec meson setup --buildtype=$meson_buildtype ..
