#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double trand(void);

int main(void) {
    srand(time(NULL));

    printf("%f\n", trand());
    printf("%f\n", trand());
    printf("%f\n", trand());

    return 0;
}

double trand(void) {
    // forgot the plus one
    return ((double) rand()) / (RAND_MAX + 1);
}
