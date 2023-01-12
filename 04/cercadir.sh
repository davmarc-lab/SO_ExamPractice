#!/bin/bash

DIRPATH="/usr/include/"
for name in `ls $DIRPATH` ; do
	if test -d $DIRPATH$name -a -r $DIRPATH$name -a $DIRPATH$name -nt $DIRPATH"stdio.h" ; then 
		echo $DIRPATH$name
	fi
done
