FLAGS=-ansi -Wpedantic -Wall -Werror

all: precedente.exe

precedente.exe: precedente.o
		gcc ${FLAGS} -o precedente.exe precedente.o

precedente.o: precedente.c
		gcc -c ${FLAGS} precedente.c

clean:
		rm -f precedente.exe *.o