#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 100000

void sort_test(void);
int comp_int(const void *p, const void *q);

int main(void) {
    sort_test();
    return 0;
}

void sort_test(void) {
    int arr[LENGTH];
    clock_t start_clock;

    for (int i = 0; i < LENGTH; i++)
        arr[i] = LENGTH - i;

    start_clock = clock();

    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), comp_int);

    printf("Sort time for %d: %f\n", LENGTH, (clock() - start_clock) / (double) CLOCKS_PER_SEC);
}

int comp_int(const void *p, const void *q) {
    const int *p1 = p;
    const int *q1 = q;

    if (*p1 < *q1)
        return -1;
    else if (*p1 == *q1)
        return 0;
    else
        return 1;
}
