#!/bin/bash
NUM=1

while ((${NUM}<=$#)) ; do
	echo "arg $NUM is ${!NUM}"
	((NUM=${NUM}+1))
done

echo "End $0"

./script2.sh "$@"
