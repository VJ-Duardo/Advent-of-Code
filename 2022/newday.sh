#!/bin/bash
day=$(($(ls -v | grep '^day*' | tail -n1 | cut -c4-5)+1))

mkdir day$day && cd $_
touch $1.txt
touch $2.py
