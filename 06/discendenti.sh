#!/bin/bash

if [[ $1 < 0 ]] ; then echo "Arg must be greater then 0" ; exit 1 ; fi

if [[ $1 -gt 0 ]] ; then
	for (( i=0 ; $i<$1 ; i=$i+1 )) ; do ./discendenti.sh $(( ${1} -1 )) & done
	wait
fi
echo $1
exit 0
