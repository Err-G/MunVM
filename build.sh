#!/bin/sh

# Variables
CC=gcc
CFLAGS='-Wall -Wextra -pedantic -std=c99'
SRC_DIR=src
EXECUTABLE=vm
HEADERS=$SRC_DIR/*.h
SOURCES=$SRC_DIR/*.c

set -e

# Compile Object Files
echo "Compiling object files..."
for file in $SOURCES; do
	filename=$(basename -- "$file")
	object_file="${filename%.c}.o"
	echo "Compiling $file..."
	$CC $CFLAGS -c -o $object_file $file
done

# Build Executable
echo "Linking object files..."
$CC $CFLAGS -o $EXECUTABLE *.o

# Clear Object files
echo "Cleaning up.."
rm -rf *.o

echo "Success!"
