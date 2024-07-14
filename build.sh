#!/bin/bash

set -xe

DEFAULT_TARGET="linux"
TARGET="$1"

function get_target()
{
    if [[ "$TARGET" == "" ]]; then
        echo $DEFAULT_TARGET
    else
        echo $TARGET
    fi
}

function find_all_c_files()
{
    find . -type f -name "*.c" | xargs echo
}

function compile()
{
    xargs -I % bash -c "$1"
}

RAYLIB_FLAGS_INCLUDE="-I./vendor/raylib-5.0_$(get_target)/include"
RAYLIB_FLAGS_LINKER="-Wl,-rpath=./vendor/raylib-5.0_$(get_target)/lib -L./vendor/raylib-5.0_$(get_target)/lib -lraylib"

MODULE_INCLUDE="-I."

CFLAGS="-Wall -Wextra $MODULE_INCLUDE $RAYLIB_FLAGS_INCLUDE $RAYLIB_FLAGS_LINKER"


mkdir -p target
mkdir -p target/debug
mkdir -p target/release

find_all_c_files | compile "cc -DFLAG_DEBUG % $CFLAGS -ggdb -o ./target/debug/game"
find_all_c_files | compile "cc % $CFLAGS -o ./target/release/game"
