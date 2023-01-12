#!/bin/bash

for (( count=0 ; $count<10 ; count=$count+1 )) ; do
	./puntini.sh 30 1>&2 &
	echo -n "$! "
done
