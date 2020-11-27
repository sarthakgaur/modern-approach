#include <stdio.h>

int num_digits(int n);

int main(void) {
    printf("1234, %d\n", num_digits(1234));

    return 0;
}

int num_digits(int n) {
    int digits = 0;

    do {
        digits++;
        n /= 10;
    } while (n > 0);

    return digits;
}
