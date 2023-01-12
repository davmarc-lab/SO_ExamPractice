CFLAGS=-ansi -Wall -Wpedantic -Werror

all: libB.so

libB.so: B.o
	gcc -shared ${CFLAGS} -fPIC -o libB.so B.o -Wl,-rpath,B.o

B.o: B.c B.h
	gcc -c -fPIC ${CFLAGS} -o B.o B.c

.PHONY: clean

clean:
	rm -f *.so *.o *~