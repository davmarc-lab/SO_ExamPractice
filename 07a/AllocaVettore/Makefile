FLAGS= -ansi -Wpedantic -Wall -Werror
all: main.exe

main.exe: main.o
		gcc ${FLAGS} -o main.exe main.o

main.o: main.c alloca.h
		gcc -c ${FLAGS} main.c

clean:
		rm -f main.exe *.o