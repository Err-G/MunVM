#!/bin/sh
set -xe

CC='cc'
CFLAGS='-Wall -Wextra -std=c99 -pedantic'
CLIBS=""
SRC="main.c"
NAME="vm"

$CC $CFLAGS -o $NAME $SRC $CLIBS
