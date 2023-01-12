#!/bin/bash
PRODOTTO=1

for (( i=1; ${i}<=$1 ; i=${i}+1  )) ; do
	PRODOTTO=$(( $i*$PRODOTTO ))
done
echo $PRODOTTO
