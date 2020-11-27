#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10000

int store_numbers(FILE *fp, int numbers[], int size);
void sort(int numbers[], int len);
int int_cmp(const void *p, const void *q);
void print_req(int numbers[], int len);
void print_num(int numbers[], int len);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: num_sort file\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "Error: could not open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int numbers[MAX_NUM], len;

    len = store_numbers(fp, numbers, MAX_NUM);

    sort(numbers, len);
    print_req(numbers, len);

    fclose(fp);

    return 0;
}

int store_numbers(FILE *fp, int numbers[], int size) {
    int n, i = 0;

    while (fscanf(fp, "%d", &n) == 1 && i < size)
        numbers[i++] = n;

    return i;
}

void sort(int numbers[], int len) {
    qsort(numbers, len, sizeof(int), int_cmp);
}

int int_cmp(const void *p, const void *q) {
    const int *p1 = p;
    const int *q1 = q;

    if (*p1 < *q1)
        return -1;
    else if (*p1 > *q1)
        return 1;
    return 0;
}

void print_req(int numbers[], int len) {
    int avg;

    if (len == 0)
        return;

    printf("Lowest number: %d\n", numbers[0]);
    printf("Highest number: %d\n", numbers[len-1]);

    if (len % 2 == 0) {
        avg = (numbers[len/2] + numbers[(len/2)-1]) / 2;
        printf("Median number: %d\n", avg);
    } else {
        printf("Median number: %d\n", numbers[len/2]);
    }
}
