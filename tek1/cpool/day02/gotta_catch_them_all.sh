#!/usr/bin/env bash

cut -d" " -f 2 | cut -d: -f 1 | grep -Ei "^$1" | wc -l
