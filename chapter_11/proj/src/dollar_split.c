#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens,
        int *fives, int *ones);

int main(void) {
    int amount, bill20, bill10, bill5, bill1;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    pay_amount(amount, &bill20, &bill10, &bill5, &bill1);

    printf("\n");
    printf("$20 bills: %d\n", bill20);
    printf("$10 bills: %d\n", bill10);
    printf(" $5 bills: %d\n", bill5);
    printf(" $1 bills: %d\n", bill1);

    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens,
        int *fives, int *ones) {
    *twenties = dollars / 20;
    dollars = dollars - *twenties * 20;

    *tens = dollars / 10;
    dollars = dollars - *tens * 10;

    *fives = dollars / 5;
    dollars = dollars - *fives * 5;

    *ones = dollars;
}
