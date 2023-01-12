#!/bin/bash

exec {FD}< /usr/include/stdio.h
NUM=0
if (( $? == 0 )) ; then
	while read -u ${FD} -N 1 -r var ; do
		(( NUM=$NUM+1 ))
	done
fi
exec {FD}>&-
echo $NUM
