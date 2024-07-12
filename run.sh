#!/bin/bash

set -xe

MODE="$1"

if [[ "$MODE" == "--debug" ]]; then
    ./target/debug/game
else
    ./target/release/game
fi
