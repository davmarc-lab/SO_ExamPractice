#!/bin/bash

NAME="variabiliglobali.h"
read A B C < define.h
NUM="${C}"

echo "#ifndef DEFINE_H" > $NAME
echo "#define DEFINE_H" >> $NAME
#declaring variables
for (( i=1 ; $i <= $NUM ; i=$i+1 )) ; do
    echo "extern int var${i};" >> $NAME
done

echo "extern int conta(void);" >> $NAME

echo "#endif" >> $NAME