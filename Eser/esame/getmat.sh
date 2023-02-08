#!/bin/bash

mat="SISTEMI OPERATIVI"

res=`grep -B 1 "$mat" lista.txt --no-group-separator | grep -v "$mat"`
var=""
for name in `grep -B 1 "$mat" lista.txt --no-group-separator | grep -v "$mat"` ; do
	echo $name > var.txt
	#VIC: assumi che le matricole inizino sempre con degli zeri.
	# se cambio i numeri di matricola il tuo codice non funziona piu'.
	var=`grep "000*" var.txt`
	if (( ${#var} == 0 )) ; then continue; fi
	echo $var
done
