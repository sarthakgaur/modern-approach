#include <stdio.h>
#include <math.h>

int main(void) {
    double x, oy, y;

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    y = 1.0;

    do {
        oy = y;
        y = (y + x/y) / 2;
    } while (fabs(oy - y) >= y * 0.00001);

    printf("Square root: %f\n", y);

    return 0;
}
