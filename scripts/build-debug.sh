#! /bin/sh

set -e

cd "$(dirname "$0")/.."


autoreconf -i

CFLAGS="-O2 -pipe -fanalyzer -ggdb" ./configure --enable-debug

make
