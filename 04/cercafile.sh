#!/bin/bash

DIRPATH="/usr/include/"

for letter in {c..g} ; do
	for name in `ls $DIRPATH?${letter}*` ; do
		if [[ -e ${name} && ( ${#name} -lt 18 || ${#name} -gt 23 ) ]] ; then
			echo ${name}
		fi
	done
done
