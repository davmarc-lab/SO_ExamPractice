#!/bin/bash

fir="esame1.txt"
sec="esame2.txt"

cat $sec

while read mat vot ; do
    out=`grep $mat $sec`
    if [[ $out == "" ]] ; then echo $mat $vot ; fi ;
done < $fir
