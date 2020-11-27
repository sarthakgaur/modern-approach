#include <stdio.h>

int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    float res = 1;
    int d = 1;

    for (int i = 1; i <= n; i++) {
        d *= i;
        res += 1.00f / d;
    }

    printf("Result: %f\n", res);

    return 0;
}
