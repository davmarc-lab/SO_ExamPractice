#!/bin/bash

dir="/usr/include/"

for name in `find $dir -mindepth 1 -type d` ; do
    str=${name#"${dir}"}
    if [[ ${#str} -ge 7 ]] ; then
        echo ${str:6:1} >> 7.txt
        if [[ ${#str} -ge 8 ]] ; then
            echo ${str:7:1} >> 8.txt
        fi
    fi
done