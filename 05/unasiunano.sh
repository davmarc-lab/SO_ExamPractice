#!/bin/bash
COUNT=1

while read RIGA ; do
	if (( $COUNT == 1 )) ; then echo "$RIGA" ; COUNT=0 ; else COUNT=1 ; fi
done
