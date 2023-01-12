CFLAGS=-ansi -Wall -Wpedantic -Werror
pathA=../LibA/
pathB=../LibB/

all: main.exe

main.o: main.c ${pathA}A.h ${pathB}B.h
	gcc -c ${CFLAGS} main.c

main.exe: main.o ${pathA}libA.so ${pathB}libB.so
	gcc ${CFLAGS} -o main.exe main.o -lA -L${pathA} -Wl,-rpath,${pathA} -lB -L${pathB} -Wl,-rpath,${pathB} -lm

.PHONY: clean

clean:
	rm -f *.so *.o *.exe *~ 