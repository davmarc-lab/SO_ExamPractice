CFLAG= -ansi -Wall -Wpedantic -Werror

all: main.exe

main.exe: main.o variabiliglobali.o
	gcc ${CFLAG} -o main.exe main.o variabiliglobali.o

main.o: main.c define.h variabiliglobali.h
	gcc -c ${CFLAG} main.c

variabiliglobali.o: variabiliglobali.c
	gcc -c ${CFLAG} variabiliglobali.c

variabiliglobali.c: define.h
	./creaC.sh

variabiliglobali.h: define.h
	./creaH.sh

.PHONY: clean

clean: 
	rm -f main.exe main.o variabiliglobali.* *~