/* Checks numbers for repeated digits */

#include <stdbool.h>
#include <stdio.h>

#define SIZE 10

int main(void) {
    int digit_seen[SIZE] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        digit_seen[digit]++;
        n /= 10;
    }

    printf("Digit:\t\t");
    for (int i = 0; i < 10; i++)
        printf("%d ", i);

    printf("\nOccurrences:\t");
    for (int i = 0; i < 10; i++)
        printf("%d ", digit_seen[i]);

    printf("\n");

    return 0;
}
