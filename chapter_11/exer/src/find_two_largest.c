#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void) {
    int largest, second_largest;
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    find_two_largest(arr, 10, &largest, &second_largest);

    printf("largest: %d, second_largest: %d\n", largest, second_largest);

    return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest) {
    *largest = 0;
    *second_largest = 0;

    for (int i = 0; i < n; i++)
        if (a[i] > a[*largest])
            *largest = i;

    for (int i = 0; i < n; i++)
        if (a[i] > a[*second_largest] && i != *largest)
            *second_largest = i;
}
