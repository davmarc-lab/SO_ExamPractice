#!/bin/bash

if [[ -e out.txt ]] ; then rm out.txt ; fi

first_path=$1
second_path=$2

exec {F1}< $first_path
exec {F2}< $second_path

current=${F1}
while read -u ${current} riga ; [[ $riga != "" ]] ; do
    echo "$riga" >> out.txt
    #swap file
    if [[ $current == $F1 ]] ; then current=$F2 ; else current=$F1 ; fi
done

if [[ $current == $F1 ]] ; then current=$F2 ; exec {F1}>&- ; else current=$F1 ; exec {F2}>&- ; fi

while read -u ${current} riga ; [[ $riga != "" ]] ; do
    echo "$riga" >> out.txt
done

exec {current}>&-
