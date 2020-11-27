#include <stdio.h>
#include <math.h>

double round_nearest(double n, int p);

int main(void) {
    double res, n;
    int p;

    printf("Enter a double value: ");
    scanf("%lf", &n);

    printf("Enter precision: ");
    scanf("%d", &p);

    res = round_nearest(n, p);
    printf("res: %f\n", res);

    return 0;
}

double round_nearest(double n, int p) {
    n = n * pow(10, p);
    n = nearbyint(n);
    n = n / pow(10, p);
    return n;
}
