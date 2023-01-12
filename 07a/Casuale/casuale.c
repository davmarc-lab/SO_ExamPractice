#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int num = 0;
    srand(time(NULL));
    while(1) {
        num++;
        if (rand() % 10 == 3)
            break;
    }
    printf("%d\n", num);
    return 0;
}