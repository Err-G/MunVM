#!/bin/sh

# Variables
CC=gcc
CFLAGS='-Wall -Wextra -pedantic -std=c99'
SRC_DIR=src
BUILD_DIR=build
EXECUTABLE=vm
HEADERS=$SRC_DIR/*.h
SOURCES=$SRC_DIR/*.c

set -e

mkdir -p $BUILD_DIR

# Compile Object Files
for file in $SOURCES; do
	filename=$(basename -- "$file")
	object_file="$BUILD_DIR/${filename%.c}.o"
	$CC $CFLAGS -c -o $object_file $file
done

# Build Executable
$CC $CFLAGS -o $BUILD_DIR/$EXECUTABLE $BUILD_DIR/*.o

echo "Success!"
