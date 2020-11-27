#include <stdio.h>

int main(void) {
    int n;
    printf("Enter a three-digit number: ");
    scanf("%d", &n);

    int huns = (n / 100) % 10;
    int tens = (n / 10) % 10;
    int last = n % 10;
    printf("The reversal is: %d%d%d\n", last, tens, huns);

    return 0;
}
