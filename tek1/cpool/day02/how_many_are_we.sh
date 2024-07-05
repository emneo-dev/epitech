#!/usr/bin/env bash

if [[ $1 = "" ]]
then
	cat | wc -l
	exit 0
fi

if [[ ${#1} != 3 ]]
then
	echo "Enter a valid city !"
	exit 84
fi

cut -d\; -f 3 | grep -ic $1
exit 0
