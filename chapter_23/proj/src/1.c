#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int a, b, c;
    double x1, x2, before_sqrt;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    printf("Enter c: ");
    scanf("%d", &c);

    before_sqrt = pow(b, 2) - (4 * a * c);

    if (before_sqrt < 0) {
        printf("Roots are complex\n");
        exit(EXIT_FAILURE);
    }

    x1 = (-b + sqrt(before_sqrt)) / (2 * a);
    x2 = (-b - sqrt(before_sqrt)) / (2 * a);

    printf("x1: %f\n", x1);
    printf("x2: %f\n", x2);

    return 0;
}
