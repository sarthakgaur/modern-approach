#include <stdio.h>

int fact(int n);

int main(void) {
    printf("fact 1: %d\n", fact(1));
    printf("fact 2: %d\n", fact(2));
    printf("fact 3: %d\n", fact(3));
    printf("fact 4: %d\n", fact(4));
    printf("fact 5: %d\n", fact(5));

    return 0;
}

int fact(int n) {
    int res = 1;

    for (int i = 1; i <= n; i++)
        res *= i;

    return res;
}

