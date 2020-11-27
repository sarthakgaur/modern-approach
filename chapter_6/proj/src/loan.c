#include <stdio.h>

int main(void)
{
    float amount, rate, payment, num_payment;

    printf("Enter amount of loan: ");
    scanf("%f", &amount);

    printf("Enter interest rate: ");
    scanf("%f", &rate);

    printf("Enter monthy payment: ");
    scanf("%f", &payment);

    printf("Enter number of payments: ");
    scanf("%f", &num_payment);

    for (int i = 0; i < num_payment; i++) {
        amount = (amount - payment) + (amount * rate / 12.0 / 100.0);
        printf("Balance remaining after %d payment: $%.2f\n", i + 1, amount);
    }

    return 0;
}
