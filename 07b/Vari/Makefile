SHELL=/bin/bash

out.txt: first.txt sec.txt
	if [[ out.txt -ot first.txt ]] ; then ./alterna.sh first.txt sec.txt ; fi
	if [[ out.txt -ot sec.txt ]] ; then ./alterna.sh first.txt sec.txt ; fi

.PHONY: print clean

print:
	cat out.txt

clean:
	rm out.txt