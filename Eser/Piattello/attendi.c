#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void attendi( int min, int max) {
	int secrandom=0;
    srand(time(NULL));
	if( min > max ) return;
	else if ( min == max ) 
		secrandom = min;
	else
		secrandom = min + ( rand()%(max-min+1) );
	do {
		/* printf("attendi %i\n", secrandom);fflush(stdout); */
		secrandom=sleep(secrandom);
		if( secrandom>0 ) 
			{ printf("sleep interrupted - continue\n"); fflush(stdout); }
	} while( secrandom>0 );
	return;
}