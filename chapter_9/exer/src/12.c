#include <stdio.h>

double inner_product(double a[], double b[], int n);

int main(void) {
    double a[] = {1.0, 2.0, 3.0};
    double b[] = {4.0, 5.0, 6.0};

    printf("inner_product: %f\n", inner_product(a, b, 3));

    return 0;
}

double inner_product(double a[], double b[], int n) {
    double sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i] * b[i];

    return sum;
}
