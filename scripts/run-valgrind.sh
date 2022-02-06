#! /bin/sh

set -e

cd "$(dirname "$0")/../src"


valgrind --leak-check=full --show-leak-kinds=all ./thing-test all
