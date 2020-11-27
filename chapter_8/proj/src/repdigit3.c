/* Checks numbers for repeated digits */

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    bool digit_seen[10] = {false};
    int digit;
    long n;

    printf("Enter numbers: ");
    scanf("%ld", &n);

    while (n > 0) {
        long temp = n;

        while (temp > 0) {
            digit = temp % 10;
            if (digit_seen[digit]) {
                printf("Repeated digit\n");
                return 0;
            }
            digit_seen[digit] = true;
            temp /= 10;
        }

        scanf("%ld", &n);
    }

    printf("No repeated digit\n");

    return 0;
}
