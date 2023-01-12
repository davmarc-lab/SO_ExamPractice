#include <math.h>
#include <stdlib.h>

static double salva = 0;

double dimezza(double x) {
    salva = cos(x) / 2;
    return salva;
}