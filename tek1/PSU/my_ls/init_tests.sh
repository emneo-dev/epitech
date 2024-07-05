#!/bin/sh

mkdir tests/general_tests
mkdir tests/general_tests/no_perm
sudo chown root tests/general_tests/no_perm
sudo chmod 0000 tests/general_tests/no_perm
mkdir tests/general_tests/to_show
touch tests/general_tests/to_show/1.txt
touch tests/general_tests/to_show/2.txt
touch tests/general_tests/to_show/3.txt