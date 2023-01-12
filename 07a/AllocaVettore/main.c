#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "alloca.h"

int main( void ){
    int32_t *p;
    int i;
    
    ALLOCA(p);
    
    for (i = 0; i < 10; i++) {
        p[i] = -19 + i;
        printf("%d ", p[i]);
        fflush(stdout);
    }
    printf("\n");

    return 0;
}