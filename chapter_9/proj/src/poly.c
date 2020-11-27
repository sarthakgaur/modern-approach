#include <stdio.h>

int poly(int n);

int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Result: %d\n", poly(n));

    return 0;
}

int poly(int n) {
    int poly = 0;
    poly += 3 * n * n * n * n * n;
    poly += 2 * n * n * n * n;
    poly -= 5 * n * n * n;
    poly -= n * n;
    poly += 7 * n;
    poly -= 6;

    return poly;
}

