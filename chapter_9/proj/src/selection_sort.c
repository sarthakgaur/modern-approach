#include <stdio.h>

#define SIZE 10

void selection_sort(int arr[], int n);

int main(void) {
    int arr[SIZE];

    printf("Enter 10 numbers: ");

    for (int i = 0; i < SIZE; i++)
        scanf("%d", &arr[i]);

    selection_sort(arr, SIZE);

    printf("In sorted order: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}

void selection_sort(int arr[], int n) {
    if (n < 2) return;

    int max_pos = 0;

    for (int i = 0; i < n; i++)
        if (arr[i] > arr[max_pos])
            max_pos = i;

    int temp;
    temp = arr[n - 1];
    arr[n - 1] = arr[max_pos];
    arr[max_pos] = temp;

    selection_sort(arr, n - 1);
}
