#!/bin/bash

exec {FD}< miofileNoNL.txt
if (( $? == 0 )) ; then
	while read -u ${FD} var ; [[ $? == 0 || ${var} != "" ]] ; do
		echo $var
	done
	exec {FD}>&-
fi
