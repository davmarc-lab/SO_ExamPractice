SHELL=/bin/bash

CFLAGS=-ansi -Wpedantic -Wall

all :		main.exe

main.exe :	main.o  funzioni.o
		gcc -o main.exe main.o funzioni.o

main.o :	main.c  funzioni.h strutture.h Makefile
		gcc -c ${CFLAGS} main.c

funzioni.o :	funzioni.c  strutture.h Makefile
		gcc -c ${CFLAGS} funzioni.c

clean:		
		-rm    main.exe *.o

