#!/bin/bash

OUT=$(echo $1 | cut -d '-' -f 1).o
SOURCE=$1

g++ -x c++ -std=gnu++17 -Wall -O2 -static \
-pipe -o $OUT $SOURCE