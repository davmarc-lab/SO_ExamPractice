#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "def.h"

int main(void){ 
	SD A={33.666}, B, C={-15.21}; 

	B.x = fA( &A );
	printf("%f\n", B.x );
        if( B.x > 1.1 )
                return( 1 );
        else
                return( 0 );
}


