CFLAGS=-ansi -Wpedantic -Wall -D_REENTRANT -D_THREAD_SAFE -D_POSIX_C_SOURCE=200112L

#VIC: togliere la riga qui sotto per creare la base da completare
CFLAGS2=-ansi -Wpedantic -Wall -D_REENTRANT -D_THREAD_SAFE -D_DEFAULT_SOURCE

LIBRARIES=-lpthread

all: 	decollo.exe

decollo.exe: decollo.o DBGpthread.o attendi.o
	gcc -o decollo.exe decollo.o DBGpthread.o attendi.o ${LIBRARIES}

decollo.o: decollo.c DBGpthread.h printerror.h attendi.h
	gcc -c ${CFLAGS} decollo.c

DBGpthread.o: DBGpthread.c printerror.h
	gcc ${CFLAGS} -c DBGpthread.c

#VIC: togliere la variabile CFLAGS2 qui sotto per creare la base da completare
attendi.o: attendi.c
	gcc ${CFLAGS2} -c attendi.c

.PHONY:	clean

clean:
	-rm -f decollo.o DBGpthread.o attendi.o decollo.exe


