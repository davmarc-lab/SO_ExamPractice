#!/bin/bash

read	DEFINE SIMBOLO VALORE ALTRO < ./define.h
echo ${VALORE}
rm -f variabiliglobali.h
for (( NUM=1; ${NUM}<=${VALORE}; NUM=${NUM}+1 )) ; do
	echo "extern int var${NUM};" >> variabiliglobali.h
done
echo 'extern int conta(void) ;' >> variabiliglobali.h

