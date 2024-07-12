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

RAYLIB_FLAGS_INCLUDE="-I./vendor/raylib-5.0_$(get_target)/include"
RAYLIB_FLAGS_LINKER="-Wl,-rpath=./vendor/raylib-5.0_$(get_target)/lib -L./vendor/raylib-5.0_$(get_target)/lib -lraylib"
CFLAGS="-Wall -Wextra $RAYLIB_FLAGS_INCLUDE $RAYLIB_FLAGS_LINKER"

mkdir -p target
mkdir -p target/debug
mkdir -p target/release

cc main.c $CFLAGS -ggdb -o ./target/debug/game
cc main.c $CFLAGS -o ./target/release/game
