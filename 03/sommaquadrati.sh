#!/bin/bash
NUM=$1
if (( $NUM<0 )) ; then
	echo "Argument must be positive"
	exit 1
fi
count=0
for num in $@ ; do
	(( sumNum=$sumNum+$num*$num ))
	(( count=$count+1 ))
	(( sumIndex=$sumIndex+$count ))
done
echo $(( ${sumNum}-${sumIndex} ))
