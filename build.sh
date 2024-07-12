#!/bin/bash

set -xe

CFLAGS=""

mkdir -p target
mkdir -p target/debug
mkdir -p target/release

cc $CFLAGS -ggdb -o ./target/debug/game main.c
cc $CFLAGS -o ./target/release/game main.c
