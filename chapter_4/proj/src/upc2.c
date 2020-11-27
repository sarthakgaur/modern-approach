/* Computes a Universal Product Code check digit */

#include <stdio.h>

int main(void) {
    int d, first5, last5;

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%5d%5d", &d, &first5, &last5);

    int i1 = first5 / 10000 % 10;
    int i2 = first5 / 1000 % 10;
    int i3 = first5 / 100 % 10;
    int i4 = first5 / 10 % 10;
    int i5 = first5 % 10;

    int j1 = last5 / 10000 % 10;
    int j2 = last5 / 1000 % 10;
    int j3 = last5 / 100 % 10;
    int j4 = last5 / 10 % 10;
    int j5 = last5 % 10;

    int first_sum, second_sum, total;
    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;

    printf("Check digit: %d\n", 9 - ((total - 1) % 10));

    return 0;
}
