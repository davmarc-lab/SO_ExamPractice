#!/bin/bash

FILES=`find /usr/include/linux/ -name "*.h" -print`

for file in $FILES ; do
    grep int ${file} | cut --bytes=-3
done