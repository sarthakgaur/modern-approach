#include <stdio.h>

int main(void) {
    int n;
    printf("Enter a two-digit number: ");
    scanf("%d", &n);

    int tens = (n / 10) % 10;
    int last = n % 10;
    printf("The reversal is: %d%d\n", last, tens);

    return 0;
}
