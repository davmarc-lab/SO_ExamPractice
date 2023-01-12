#!/bin/bash
count=0
for name in "$@" ; do
	if (( ($count%2)==0 )) ; then
		even=$even"$name "
	else
		odd=$odd"$name "
	fi
	(( count=$count+1 ))
done
echo "Even: $even"
echo "Odd: $odd"
echo "Tot: $even$odd"
