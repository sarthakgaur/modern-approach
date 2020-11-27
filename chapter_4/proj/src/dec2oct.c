#include <stdio.h>

int main(void) {
    int n;
    printf("Enter number between 0 and 32767: ");
    scanf("%d", &n);

    int r1 = n % 8;

    n /= 8;
    int r2 = n % 8;

    n /= 8;
    int r3 = n % 8;

    n /= 8;
    int r4 = n % 8;

    n /= 8;
    int r5 = n % 8;

    printf("In octal, your number is: %d%d%d%d%d\n", r5, r4, r3, r2, r1);

    return 0;
}
