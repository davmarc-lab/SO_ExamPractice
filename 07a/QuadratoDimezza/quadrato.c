#include <math.h>
#include <stdlib.h>

static double salva = 0;

double quadrato(double x) {
    salva = sqrt(x);
    return salva;
}