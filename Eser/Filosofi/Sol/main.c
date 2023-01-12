/* file:  5filosofiNo2ForchetteAssieme.c  */

#ifndef _THREAD_SAFE
	#define _THREAD_SAFE
#endif
#ifndef _POSIX_C_SOURCE
	#define _POSIX_C_SOURCE 200112L
#endif


#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdint.h>	/* uint64_t */
#include <sys/time.h>	/* gettimeofday()    struct timeval */
#include <pthread.h> 
#include "printerror.h"
#include "DBGpthread.h"

#define NUMFILOSOFI 5

/* variabili da proteggere */
/* la forchetta a sinistra di un filosofo
   ha lo stesso indice del filosofo.
	 Il filosofo di indice ZERO prende per prima
	 la forchetta alla sua sinistra.
	 Tutti gli altri filosofi prendono per prima
	 la loro forchetta di destra
	 */
int forchettaoccupata[NUMFILOSOFI];

/* variabili per la sincronizzazione */
pthread_mutex_t	 mutexForchetta[NUMFILOSOFI]; 

/* gli indici dei filosofi crescono in senso orario, da 0 a NUMFILOSOFI-1 
	indice	indiceforchAsinistra  indiceforcAdestra
	0		0		4
	1		1		0
	2		2		1
	3		3		2
	4		4		3
	indice	indiceprimaforc	  indicsecondaforc
	0		0		4    <--inversione contro deadlock
	1		0		1
	2		1		2
	3		2		3
	4		3		4

queste 2 funzioni qui sotto servono per implementare
la versione anti-deadlock che usa l'inversione 
della prima forchetta presa
*/

int indiceprimaforchetta( int indicefilosofo ) {
	if( indicefilosofo==0 )	return( 0 );
	else			return( indicefilosofo-1 );
}
int indicesecondaforchetta( int indicefilosofo ) {
	if( indicefilosofo==0 )	return( NUMFILOSOFI-1 );
	else			return( indicefilosofo );
}

void *filosofo (void *arg) 
{ 
	char Flabel[128];
	int indice;

	indice=*((int*)arg);
	free(arg);
	sprintf(Flabel,"F%d",indice);

	
	while(1) {
		int indiceforchetta1;
		int indiceforchetta2;
		printf("filosofo %s sta pensando \n", Flabel ); 
		fflush(stdout);
		/* il filosofo pensa per 1/2 di sec piu o meno */
		DBGnanosleep( 500000000+indice*1000000, Flabel );

		/* il filosofo prende le due forchette NON IN MANIERA ATOMICA */
		/* AGGIUNGERE CODICE */
		/* prendo la prima forchetta */
		/* prendo la mutua esclusione sulla prima forchetta */
		indiceforchetta1=indiceprimaforchetta(indice);
		printf("filosofo %s vuole prima forchetta %i\n", Flabel, indiceforchetta1 ); 
		fflush(stdout);
		DBGpthread_mutex_lock(&mutexForchetta[indiceforchetta1],Flabel); 

		/* il filosofo aspetta 2 sec piu' o meno
			prima di prendere l'altra forchetta */
		DBGnanosleep( 2000000000+indice*1000000, Flabel );

		/* prendo la seconda forchetta */
		/* prendo la mutua esclusione sulla seconda forchetta */
		indiceforchetta2=indicesecondaforchetta(indice);
		printf("filosofo %s vuole seconda forchetta %i \n", Flabel, indiceforchetta2 ); 
		fflush(stdout);
		DBGpthread_mutex_lock(&mutexForchetta[indiceforchetta2],Flabel); 
		/* FINE AGGIUNTA CODICE */

		/*  FILOSOFO MANGIA */
		printf("filosofo %s MANGIA \n", Flabel ); 
		fflush(stdout);
		/* il filosofo mangia per circa 11 sec */
		DBGnanosleep( 11000000000+indice*1000000, Flabel );
		printf("filosofo %s FINISCE DI MANGIARE \n", Flabel ); 
		fflush(stdout);

		/* il filosofo rilascia le forchette */
		/* AGGIUNGERE CODICE */
		/* rilascio la mutua esclusione sulla seconda forchetta */
		printf("filosofo %s rilascia seconda forchetta %i\n", Flabel, indiceforchetta2 ); 
		fflush(stdout);
		DBGpthread_mutex_unlock(&mutexForchetta[indiceforchetta2],Flabel); 
		/* rilascio la mutua esclusione sulla prima forchetta */
		printf("filosofo %s rilascia prima forchetta %i\n", Flabel, indiceforchetta1 ); 
		fflush(stdout);
		DBGpthread_mutex_unlock(&mutexForchetta[indiceforchetta1],Flabel); 
		/* FINE AGGIUNTA CODICE */

	}
	pthread_exit(NULL); 
} 

int main (int argc, char* argv[] ) 
{ 
	pthread_t    th; 
	int  rc, i, *intptr;

	for(i=0;i<NUMFILOSOFI;i++) {
		rc = pthread_mutex_init( &mutexForchetta[i], NULL); 
		if( rc ) PrintERROR_andExit(rc,"pthread_mutex_init failed");
	}

	for(i=0;i<NUMFILOSOFI;i++) {
		intptr=malloc(sizeof(int));
		if( !intptr ) { printf("malloc failed\n");exit(1); }
		*intptr=i;
		rc=pthread_create( &th,NULL,filosofo,(void*)intptr); 
		if(rc) PrintERROR_andExit(rc,"pthread_create failed");
	}

	pthread_exit(NULL); 

	return(0); 
} 
  
  
  
