#!/bin/bash

count=0

while (( $RANDOM%10 != 2 )) ; do
	(( count=$count+1 ))
done
echo "$count"
