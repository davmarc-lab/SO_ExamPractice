CFLAGS=-ansi -Wall -Wpedantic -Werror

all: libA.so

libA.so: A.o
	gcc -shared ${CFLAGS} -fPIC -o libA.so A.o -Wl,-rpath,A.o

A.o: A.c A.h
	gcc -c -fPIC ${CFLAGS} -o A.o A.c

.PHONY: clean

clean:
	rm -f *.so *.o *~