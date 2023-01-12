#include <stdio.h>
#include <stdlib.h>
#include "quadrato.h"
#include "dimezza.h"

static double salva = 0;

int main(void) {
    salva = quadrato(dimezza(13.17));
    printf("%f\n", salva);
    return 0;
}