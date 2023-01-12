#!/bin/bash

while read A B C D ; do
	if [[ $? -eq 0 ]] ; then
		echo "$D $C"
	fi
done
