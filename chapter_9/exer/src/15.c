#include <stdio.h>

double median(double x, double y, double z);

int main(void) {
    printf("median: %g\n", median(3, 1, 2));
    printf("median: %g\n", median(1, 3, 2));
    printf("median: %g\n", median(1, 2, 3));

    return 0;
}

double median(double x, double y, double z) {
    double temp;

    if (x > y) {
        temp = x;
        x = y;
        y = temp;
    }

    if (y > z) {
       temp = y;
       y = z;
       z = temp;
    }

    if (x > y) {
        temp = x;
        x = y;
        y = temp;
    }

    return y;
}
