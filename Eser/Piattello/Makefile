CFLAGSCONSTRERROR=-ansi -Wpedantic -Wall -D_REENTRANT -D_THREAD_SAFE -D_POSIX_C_SOURCE=200112L
CFLAGS=-ansi -Wpedantic -Wall -D_REENTRANT -D_THREAD_SAFE -D_DEFAULT_SOURCE
LFLAGS=

LIBRARIES= -lpthread
DBGPTHREADFUNCTION_SOURCE_DIR=./

all: 	 main.exe

main.exe:  main.o DBGpthread.o attendi.o
	gcc ${LFLAGS} -o main.exe main.o DBGpthread.o ${LIBRARIES}

main.o: main.c attendi.h ${DBGPTHREADFUNCTION_SOURCE_DIR}DBGpthread.h ${DBGPTHREADFUNCTION_SOURCE_DIR}printerror.h
	gcc -c ${CFLAGS} -I${DBGPTHREADFUNCTION_SOURCE_DIR} main.c 

DBGpthread.o: ${DBGPTHREADFUNCTION_SOURCE_DIR}DBGpthread.c ${DBGPTHREADFUNCTION_SOURCE_DIR}printerror.h
	gcc ${CFLAGSCONSTRERROR} -c ${DBGPTHREADFUNCTION_SOURCE_DIR}DBGpthread.c -I${DBGPTHREADFUNCTION_SOURCE_DIR} 

attendi.o: attendi.c
	gcc ${CFLAGS} -c attendi.c

.PHONY:	clean

clean:
	-rm -f main.o DBGpthread.o attendi.o main.exe


