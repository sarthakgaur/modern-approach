#include <stdio.h>

int largest(int a[], int n);
float average(int a[], int n);
int positive_num(int a[], int n);

int main(void) {
    int a[] = {3, 6, 2, -1, 9};

    printf("largest: %d\n", largest(a, 5));
    printf("average: %f\n", average(a, 5));
    printf("positive_num: %d\n", positive_num(a, 5));

    return 0;
}

int largest(int a[], int n) {
    if (n == 0) return 0;

    int max = a[0];

    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

float average(int a[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return (float) sum / n;
}

int positive_num(int a[], int n) {
    int pos_num = 0;

    for (int i = 0; i < n; i++)
        if (a[i] > 0)
            pos_num++;

    return pos_num;
}
