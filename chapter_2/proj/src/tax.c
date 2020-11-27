#include <stdio.h>

int main(void)
{
    float amount;
    printf("Enter an amount: ");
    scanf("%f", &amount);

    float after_tax = (amount * 0.05f) + amount;

    printf("With tax added: $%.2f\n", after_tax);

    return 0;
}
