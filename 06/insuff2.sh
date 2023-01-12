#!/bin/bash

while read name surname id score ; do
	if (( $score < "18" )) ; then
		line=`grep ${id} RisultatiProvaPratica1.txt | wc -l`
		if [[ "$line" == "0" ]] ; then
			echo $id $name $surname $score
		fi
	fi
done < RisultatiProvaPratica2.txt | sort
