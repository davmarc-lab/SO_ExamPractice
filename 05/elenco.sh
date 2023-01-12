#!/bin/bash

LongNomiDirectory=0
count=0
for var in `ls ./` ; do
	if [[ -d $var ]] ; then (( LongNomiDirectory=$LongNomiDirectory+${#var} )) ; else (( count=$count+1 )) ; fi
done
echo "File cout : $count"
echo "WC directories : $LongNomiDirectory"
