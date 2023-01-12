#!/bin/bash

i=${#1}
echo $i
echo $1

echo $1 | while true ; do
	read -n 1 var
	if (( $i < 0 )) ; then echo $res ; break ; fi
	res=${var}${res}
	(( i=i-1 ))
done
