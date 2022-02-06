#! /bin/sh

set -e

cd "$(dirname "$0")/.."


autoreconf -i

CFLAGS="-O2 -pipe -ggdb -fanalyzer" ./configure --enable-debug

make
