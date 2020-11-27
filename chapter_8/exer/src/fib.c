#include <stdio.h>

#define SIZE 40

int main(void) {
    int fib[SIZE] = {[0] = 0, [1] = 1};

    for (int i = 2; i < SIZE; i++)
        fib[i] = fib[i-1] + fib[i-2];

    for (int i = 0; i < SIZE; i++)
        printf("%d\n", fib[i]);

    return 0;
}
