#!/bin/bash

OUT=""
while read A B ; do
	OUT=${OUT}$B
done < $1
echo $OUT
