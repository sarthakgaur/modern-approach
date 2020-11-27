#include <stdio.h>

int *find_largest(int a[], int n);

int main(void) {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *max = find_largest(arr, 10);

    printf("largest: %d\n", *max);

    return 0;
}

int *find_largest(int a[], int n) {
    int max_off = 0;

    for (int i = 0; i < n; i++)
        if (a[i] > a[max_off])
            max_off = i;

    return &a[max_off];
}
