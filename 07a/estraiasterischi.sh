#!/bin/bash
#uncomment after tries
sleep 2
TUTTO=
while read riga ; do
	riga="${riga# }"
	
	while [[ -n "${riga}" ]] ; do
		parola="${riga%% *}"

		if [[ "${parola}" == "${riga}" ]] ; then
			riga=
		else
			riga="${riga#* }"
		fi

		if echo "${parola}" | grep '*' > /dev/null ; then
			TUTTO="${TUTTO} ${parola}" 
		fi
	done
done
echo "$TUTTO"
