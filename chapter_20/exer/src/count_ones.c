#include <stdio.h>

int count_ones(unsigned char ch);

int main(void) {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);
    printf("1s in %d: %d\n", n, count_ones(n));

    return 0;
}

int count_ones(unsigned char ch) {
    int count = 0;

    if (ch & 1) count++;
    if (ch >> 1 & 1) count++;
    if (ch >> 2 & 1) count++;
    if (ch >> 3 & 1) count++;
    if (ch >> 4 & 1) count++;
    if (ch >> 5 & 1) count++;
    if (ch >> 6 & 1) count++;
    if (ch >> 7 & 1) count++;

    return count;
}
