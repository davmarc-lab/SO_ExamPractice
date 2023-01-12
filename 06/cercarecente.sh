#!/bin/bash

files=`find /usr/include/linux/ -mindepth 1 -type f -name *.h`

if [[ -z $files ]] ; then echo "File not found." ; exit 1 ; fi

for file in $files ; do
	for res in $files ; do break; done ;
	if [[ $file -ot $res ]] ; then
		res=$file
	fi
done
echo $res
exit 0
