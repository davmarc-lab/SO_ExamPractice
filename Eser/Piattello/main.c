/* file:  piattello.c */

#ifndef _THREAD_SAFE
	#define _THREAD_SAFE
#endif
#ifndef _POSIX_C_SOURCE
	#define _POSIX_C_SOURCE 200112L
#endif

/* la   #define _POSIX_C_SOURCE 200112L   e' dentro printerror.h */
#ifndef _BSD_SOURCE
#define _BSD_SOURCE     /* per random e srandom */
#endif


/* messo prima perche' contiene define _POSIX_C_SOURCE */
#include "printerror.h"

#include <unistd.h>   /* exit() etc */
#include <stdlib.h>     /* random  srandom */
#include <stdio.h>
#include <string.h>     /* per strerror_r  and  memset */
#include <sys/types.h>
#include <signal.h>
#include <sys/time.h> /*gettimeofday() struct timeval timeval{} for select()*/
#include <time.h> /* timespec{} for pselect() */
#include <limits.h> /* for OPEN_MAX */
#include <errno.h>
#include <assert.h>
#include <stdint.h>     /* uint64_t intptr_t */
#include <inttypes.h>   /* per PRIiPTR */
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>

#include "DBGpthread.h"

#define NUMTIRATORI 10
#define DELAYTRADUEPIATTELLI8sec 8

/* dati da proteggere */
int PiattelloInVolo=0;	/* all'inizio nessun piattello e' in volo */
int PiattelloColpito=0;	/* non richiesto, solo per contare quanti hanno colpito il piattello */

/* variabili per la sincronizzazione */
pthread_mutex_t mutex;
pthread_cond_t condSvegliaTiratori;
void attendi( int min, int max) {
	int secrandom=0;
	if( min > max ) return;
	else if ( min == max ) 
		secrandom = min;
	else
		secrandom = min + ( random()%(max-min+1) );
	do {
		/* printf("attendi %i\n", secrandom);fflush(stdout); */
		secrandom=sleep(secrandom);
		if( secrandom>0 ) 
			{ printf("sleep interrupted - continue\n"); fflush(stdout); }
	} while( secrandom>0 );
	return;
}

void *Tiratore (void *arg) 
{ 
	char Plabel[128];
	intptr_t indice;

	indice=(intptr_t)arg;
	sprintf(Plabel,"Tiratore%" PRIiPTR "",indice);

	/*  da completare  */

	while ( 1 ) {


		/*  da completare  */

		DBGpthread_mutex_lock(&mutex, Plabel);

		/* il tiratore  attende l'inizio del volo del piattello */
		printf("tiratore %s attende piattello \n", Plabel);
	        fflush(stdout);

		/*  da completare  */

		if (PiattelloInVolo == 0) {
			DBGpthread_cond_wait(&condSvegliaTiratori, &mutex, Plabel);
		}
		DBGpthread_mutex_unlock(&mutex, Plabel);

		printf("tiratore %s mira e .... \n", Plabel);
	        fflush(stdout);

		/*  da completare  */


		/* il tiratore si prepara a sparare impiegando da 2 a 4 secondi */
		attendi( 2, 4 );


		/*  da completare  */
		DBGpthread_mutex_lock(&mutex, Plabel);

		if (PiattelloColpito == 0 && PiattelloInVolo == 1) {
			PiattelloColpito = 1;
			printf("tiratore %s COLPITO\n", Plabel);
		}

		/* il tiratore finisce il tentativo di sparare al piattello in volo */
		printf("tiratore %s ha sparato o e' arrivato tardi\n", Plabel);
	        fflush(stdout);


		/*  da completare  */

		DBGpthread_mutex_unlock(&mutex, Plabel);
	}
	pthread_exit(NULL); 
}


void *Piattello (void *arg) 
{ 
	char Plabel[128];
	intptr_t indice;

	indice=(intptr_t)arg;
	sprintf(Plabel,"Piattello%" PRIiPTR "",indice);


	/*  da completare  */
	DBGpthread_mutex_lock(&mutex, Plabel);

	if (PiattelloInVolo == 1) {
		pthread_exit(NULL);
	}

	printf("piattelo %s inizia volo\n", Plabel);
        fflush(stdout);

	/*  da completare  */
	PiattelloInVolo = 1;
	PiattelloColpito = 0;
	DBGpthread_cond_broadcast(&condSvegliaTiratori, Plabel);
	DBGpthread_mutex_unlock(&mutex, Plabel);


	/* il piattello vola per tre secondi */
	attendi( 3, 3 );


	/*  da completare  */

	DBGpthread_mutex_lock(&mutex, Plabel);

	PiattelloInVolo = 0;
	PiattelloColpito = 0;
	
	printf("piattelo %s finisce volo e termina\n", Plabel);
       	fflush(stdout);

	/*  da completare  */

	DBGpthread_mutex_unlock(&mutex, Plabel);


	pthread_exit(NULL); 
}


int main ( int argc, char* argv[] ) 
{ 
	pthread_t    th; 
	int  rc;
	uintptr_t i=0;
	int seme;
	pthread_attr_t attr;

	/* variabile per creare thread detached */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	seme=time(NULL);
        srandom(seme);

	/* INIZIALIZZATE LE VOSTRE VARIABILI CONDIVISE / fate voi */

	rc = pthread_cond_init(&condSvegliaTiratori, NULL);
	if( rc ) PrintERROR_andExit(rc,"pthread_cond_init failed");

	rc = pthread_mutex_init(&mutex, NULL); 
	if( rc ) PrintERROR_andExit(rc,"pthread_mutex_init failed");

	PiattelloInVolo=0;	/* all'inizio non c'e' nessun piattello in volo */
	PiattelloColpito=0;

	/* CREAZIONE PTHREAD */
	for(i=0;i<NUMTIRATORI;i++) {
		rc=pthread_create(&th,NULL,Tiratore,(void*)i); 
		if(rc) PrintERROR_andExit(rc,"pthread_create failed");
	}
	i=0;
	while(1) {
			/* un nuovo piattello ogni 6 secondi */
			attendi( DELAYTRADUEPIATTELLI8sec, DELAYTRADUEPIATTELLI8sec );
			i++;
			rc=pthread_create(&th,&attr,Piattello,(void*)i); 
			if(rc) PrintERROR_andExit(rc,"pthread_create failed");
	}

	pthread_exit(NULL);
	return(0); 
} 
  
