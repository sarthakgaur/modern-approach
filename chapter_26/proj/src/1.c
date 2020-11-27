#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMES 1000

void print_rand(void);

int main(void) {
    srand(time(NULL));

    print_rand();

    return 0;
}

void print_rand(void) {
    int n, count0 = 0, count1 = 0;

    for (int i = 0; i < TIMES; i++) {
        n = rand();
        if (n % 2 == 0) {
            putchar('0');
            count0++;
        } else {
            putchar('1');
            count1++;
        }
    }

    putchar('\n');

    printf("count0: %d\n", count0);
    printf("count1: %d\n", count1);
}
