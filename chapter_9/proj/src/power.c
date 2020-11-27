#include <stdio.h>

int power(int x, int n);

int main(void) {
    int x, n;
    
    printf("Enter a number: ");
    scanf("%d", &x);

    printf("Enter the exponent: ");
    scanf("%d", &n);

    printf("Result: %d\n", power(x, n));

    return 0;
}

int power(int x, int n) {
    if (n == 0) return 1;

    if (n % 2 == 0) {
        int res = power(x, n / 2);
        return res * res;
    } else
        return x * power(x, n - 1);
}
