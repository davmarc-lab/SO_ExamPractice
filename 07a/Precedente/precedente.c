#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int dammi_precedente(unsigned int n) {
    static unsigned int old = 0;
    unsigned int tmp;
    tmp = old;
    old = n;
    return tmp;
}

int main(void) {
    unsigned int c = 0;
    int i = 0;
    srand(time(NULL));
    while(1) {
        c = rand();
        i++;
        if (dammi_precedente(c) % 10 == 3)
            break;
    }

    printf("%d\n", i);
    return 0;
}