#!/bin/bash

if [[ -e out.txt ]] ; then rm out.txt ; fi

for (( i=0 ; i < 10 ; i=i+1 )) ; do
    ./genera.sh out.txt
done
