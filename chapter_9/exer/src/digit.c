#include <stdio.h>

int digit(int n, int k);

int main(void) {
    printf("829, 1: %d\n", digit(829, 1));
    printf("829, 2: %d\n", digit(829, 2));
    printf("829, 3: %d\n", digit(829, 3));
    printf("829, 4: %d\n", digit(829, 4));

    return 0;
}

int digit(int n, int k) {
    int k_digit;

    while (k > 0) {
        if (n == 0) return 0;

        k_digit = n % 10;
        n /= 10;
        k--;
    }

    return k_digit;
}
