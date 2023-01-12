#!/bin/bash
NOMIFILES=`ls`
for nome1 in ${NOMIFILES} ; do
	for nome2 in ${NOMIFILES} ; do
		for nome3 in ${NOMIFILES} ; do
			# echo "(${nome1};${nome2};${nome3})" ;
			echo \(${nome1}\;${nome2}\;${nome3}\) ;
		done
	done
done
