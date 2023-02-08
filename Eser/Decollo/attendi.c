/* file:  attendi.c */ 

#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 

int seed=0;

void attendi( int secmin, int secmax) {
	int secrandom=0;
	static int inizializzato=0;
	if( inizializzato==0 ) {
		/* Inizializzazione generatore numeri casuali */
		srandom( seed );
		inizializzato=1;
	}
	if( secmin > secmax ) return;
	else if ( secmin == secmax )
		secrandom = secmin;
	else
		secrandom = secmin + ( random()%(secmax-secmin+1) );
	do {
		/* printf("attendi %i\n", secrandom);fflush(stdout); */
		secrandom=sleep(secrandom);
		if( secrandom>0 )
		{ printf("sleep interrupted - continue\n"); fflush(stdout); }
	} while( secrandom>0 );

return;
}


