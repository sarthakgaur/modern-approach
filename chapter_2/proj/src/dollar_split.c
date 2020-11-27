#include <stdio.h>

int main(void)
{
    int amount;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    int bill20 = amount / 20;
    amount = amount - bill20 * 20;

    int bill10 = amount / 10;
    amount = amount - bill10 * 10;

    int bill5 = amount / 5;
    amount = amount - bill5 * 5;

    int bill1 = amount / 1;
    amount = amount - bill1 * 1;

    printf("\n");
    printf("$20 bills: %d\n", bill20);
    printf("$10 bills: %d\n", bill10);
    printf(" $5 bills: %d\n", bill5);
    printf(" $1 bills: %d\n", bill1);

    return 0;
}
