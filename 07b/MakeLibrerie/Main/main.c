#include <stdio.h>
#include <stdlib.h>
#include "../LibB/B.h"
#include "../LibA/A.h"

int main(int argc, char* arg[]) {
    int num = atoi(arg[1]);
    printf("Number -> %d\n", num);
    printf("Res -> %f\n", calcolaA(calcolaB(num)));
    return 0;
}