/* Computes a Universal Product Code check digit */

#include <stdio.h>

int main(void) {
    int first6, last6;

    printf("Enter the first 12 digits of an EAN: ");
    scanf("%6d%6d", &first6, &last6);

    int i1 = first6 / 100000 % 10;
    int i2 = first6 / 10000 % 10;
    int i3 = first6 / 1000 % 10;
    int i4 = first6 / 100 % 10;
    int i5 = first6 / 10 % 10;
    int i6 = first6 % 10;

    int j1 = last6 / 100000 % 10;
    int j2 = last6 / 10000 % 10;
    int j3 = last6 / 1000 % 10;
    int j4 = last6 / 100 % 10;
    int j5 = last6 / 10 % 10;
    int j6 = last6 % 10;

    int first_sum, second_sum, total;
    first_sum = i2 + i4 + i6 + j2 + j4 + j6;
    second_sum = i1 + i3 + i5 + j1 + j3 + j5;
    total = 3 * first_sum + second_sum;

    printf("Check digit: %d\n", 9 - ((total - 1) % 10));

    return 0;
}
