#!/bin/bash

sec=$1
count=0

while (( $count < $sec )) ; do
	sleep 1
	echo -n "$BASHPID "
	(( count=$count+1 ))
done
echo ""
