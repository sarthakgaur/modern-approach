#include <stdio.h>

int main(void) {
    long double fact, n;

    printf("Enter a positive integer: ");
    scanf("%Lf", &n);

    fact = 1;

    for (long double i = 1; i <= n; i++)
        fact *= i;

    printf("Factorial of %.0Lf: %Lf\n", n, fact);

    return 0;
}
