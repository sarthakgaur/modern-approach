#include <stdio.h>

int main(void) {
    int m, n, r;

    printf("Enter two integers: ");
    scanf("%d%d", &m, &n);

    printf("Greatest common divisor: ");

    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }

    printf("%d\n", m);

    return 0;
}
