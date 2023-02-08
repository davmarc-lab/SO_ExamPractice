/* file:  decollo.c 
*/ 

#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <stdint.h>
#include <pthread.h> 
#include "printerror.h"
#include "DBGpthread.h"

/* VIC:  INIZIO PRIMA PARTE DA INSERIRE */
/*	SUGGERIMENTO: come sapere quali funzioni e quali variabili globali
		sono implementate nell'altro modulo attendi.c ?  
*/
#include "attendi.h"

/* VIC:  FINE PRIMA PARTE DA INSERIRE */


#define NUMAEREI 10
#define SECSCREAZIONE 22

/* dati da proteggere */

int TurnoGlob=0; /* assegna il numero per il turno */
int Turno=0; /* chi e' di turno per occupare la pista di rullaggio e poi decollare */
/* variabili per la sincronizzazione */
pthread_mutex_t  mutex; 
pthread_cond_t   condAttesaRullaggio, condAttesaDecollo; 

/* VIC:  INIZIO SECONDA PARTE DA INSERIRE */
/* VIC: aggiungete le altre variabili globali che vi servono.
	SUGGERIMENTO 1:
		la variabile Turno serve anche per sapere
		se si puo' entrare nella pista di rullaggio.
		Ma come fare a sapere se la pista di decollo e' libera o occupata?
*/


int PistaDecolloOccupata=0;

/* VIC:  FINE SECONDA PARTE DA INSERIRE */

/* variabile per creare thread detached */
pthread_attr_t attr;

 
void *Aereo (void *arg) 
{ 
	char Plabel[128];
	unsigned int indice;
	int mioturno=0;

	indice=*((int*)arg);
	free(arg);
	sprintf(Plabel,"A%d",indice);

	/* l'aereo prende biglietto per turno */	
	DBGpthread_mutex_lock(&mutex,Plabel); 
	mioturno=TurnoGlob;
	TurnoGlob++;
	printf("aereo %s ha turno %i \n", Plabel, mioturno ); 
	fflush(stdout);

	/* VIC:  INIZIO TERZA PARTE DA COMPLETARE */
	/* attendo che sia il mio turno di impegnare la pista di rullaggio */
	while ( mioturno != Turno ) {
		/*
		printf("aereo %s ha turno %i ma non e' il suo turno %i \n", Plabel, mioturno, Turno ); 
		fflush(stdout);
		*/
		DBGpthread_cond_wait(&condAttesaRullaggio,&mutex,Plabel);
	}



	/* aereo ora e' di turno per entrare in pista di rullaggio  */
	printf("aereo %s in pista rullaggio turno %i \n", Plabel, mioturno ); 
	fflush(stdout);



	DBGpthread_mutex_unlock(&mutex,Plabel); 


	/* VIC:  FINE TERZA PARTE DA COMPLETARE */

	attendi(1,2); /* aereo impiega 1-2 sec per rullare */

  /* VIC:  INIZIO QUARTA PARTE DA COMPLETARE */
  /* aereo e' al termine della pista di rullaggio,
      ATTENDE CHE pista decollo sia libera */

	DBGpthread_mutex_lock(&mutex,Plabel); 
	while ( PistaDecolloOccupata == 1 ) {
		DBGpthread_cond_wait(&condAttesaDecollo,&mutex,Plabel);
	}


	/* libero pista rullaggio e avviso prossimo di turno */
	Turno++;
	DBGpthread_cond_broadcast(&condAttesaRullaggio,Plabel);


	/* occupo pista decollo e poi inizio decollo */


	PistaDecolloOccupata=1;



	printf("aereo %s in pista decollo turno %i \n", Plabel, mioturno ); 
	fflush(stdout);




	DBGpthread_mutex_unlock(&mutex,Plabel);


	/* VIC:  FINE QUARTA PARTE DA COMPLETARE */

	attendi(1,2); /* impiego 1-2 sec per decollare */

  /* aereo finisce decollo, vola e libera pista di decollo */
	DBGpthread_mutex_lock(&mutex,Plabel); 

	/* VIC:  INIZIO QUINTA PARTE DA COMPLETARE */
	PistaDecolloOccupata=0;

	/* VIC:  FINE QUINTA PARTE DA COMPLETARE */
	DBGpthread_cond_signal(&condAttesaDecollo,Plabel);

	printf("aereo %s decollato vola via turno %i \n", Plabel, mioturno ); 
	fflush(stdout);

	DBGpthread_mutex_unlock(&mutex,Plabel);

	/* aereo va via e thread termina */
	pthread_exit(NULL); 
} 

int main (int argc, char* argv[] ) 
{ 
	pthread_t    th; 
	int  rc, i, *intptr;
	unsigned int I=0;

	/* Inizializzazione variabili */
	seed=time(NULL); /* inizializzo seme per generatore casuale */

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	rc = pthread_mutex_init(&mutex, NULL); 
	if( rc ) PrintERROR_andExit(rc,"pthread_mutex_init failed");

	/* inizializzazione vostre variabili */
	rc = pthread_cond_init(&condAttesaRullaggio, NULL);
	if( rc ) PrintERROR_andExit(rc,"pthread_cond_init failed");
	rc = pthread_cond_init(&condAttesaDecollo, NULL);
	if( rc ) PrintERROR_andExit(rc,"pthread_cond_init failed");


	while(1) { /* ogni 22 secondi creo 10 aerei */
		for(i=0;i<NUMAEREI;i++) {
			intptr=malloc(sizeof(int));
			if( !intptr ) { printf("malloc failed\n");exit(1); }
			*intptr=I;
			I++;
			rc=pthread_create( &th,NULL,Aereo,(void*)intptr); 
			if(rc) PrintERROR_andExit(rc,"pthread_create failed");
		}
		attendi(SECSCREAZIONE,SECSCREAZIONE);
	}

	pthread_exit(NULL); 

	return(0); 
} 

