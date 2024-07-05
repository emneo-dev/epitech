#!/usr/bin/env bash

cat Day02/passwd | sed -n "n;p" | cut -d: -f 1 | rev | sort -dr | sed -n -e "$MY_LINE1,$MY_LINE2 p" -e "$MY_LINE2 q" | paste -d, -s | sed --expression='s/,/, /g' | sed --expression='s/$/./g'
