#!/bin/bash

NAME="variabiliglobali.c"
read A B C < define.h
NUM="${C}"

echo "#include \"define.h\"" > $NAME
#declaring variables
for (( i=1 ; $i <= $NUM ; i=i+1 )) ; do
    echo "int var${i} = ${i};" >> $NAME
done

echo "int conta(void) {" >> $NAME
echo -n "int res = 0 " >> $NAME
for (( i=1 ; i <= $NUM ; i=i+1 )) ; do
    echo -n "+ var${i} " >> $NAME
done
echo ";" >> $NAME
echo "return res;" >> $NAME
echo "}" >> $NAME
echo ""