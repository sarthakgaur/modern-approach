#include <stdio.h>

int gcd(int m, int n);

int main(void) {
    printf("10, 15: %d\n", gcd(10, 15));
    printf("44, 22: %d\n", gcd(44, 22));
    printf("14, 84: %d\n", gcd(14, 84));

    return 0;
}

int gcd(int m, int n) {
    return n == 0 ? m : gcd(n, m % n);
}
