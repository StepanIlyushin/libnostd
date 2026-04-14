#1/bin/sh -e

BASEDIR=$(realpath "$(dirname "$0")")
BASEDIR=$(realpath "$BASEDIR/..")

cmake -S "$ROOTDIR" -B "$ROOTDIR/build"
cmake --build "$ROOTDIR/build"