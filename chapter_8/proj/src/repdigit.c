/* Checks numbers for repeated digits */

#include <stdio.h>
#include <stdbool.h>

// codes for state
#define NOT_PRESENT 0
#define PRESENT 1
#define REPEATED 2

#define SIZE 10

int main(void) {
    int digit_seen[SIZE] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    bool has_repeat = false;

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit] == NOT_PRESENT) {
            digit_seen[digit] = PRESENT;
        } else if (digit_seen[digit] == PRESENT) {
            has_repeat = true;
            digit_seen[digit] = REPEATED;
        }
        n /= 10;
    }

    if (has_repeat) {
        printf("Repeated digit(s): ");
        for (int i = 0; i < SIZE; i++) {
            if (digit_seen[i] == REPEATED) {
                printf("%d ", i);
            }
        }
    } else {
        printf("No repeated digit");
    }

    printf("\n");

    return 0;
}
