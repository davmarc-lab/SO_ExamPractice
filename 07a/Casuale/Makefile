FLAG= -ansi -Wall -Wpedantic -Werror

all: casuale.exe

casuale.exe: casuale.o
		gcc ${FLAG} -o casuale.exe casuale.o

casuale.o: casuale.c
		gcc -c ${FLAG} casuale.c
