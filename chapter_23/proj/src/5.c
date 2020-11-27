#include <stdio.h>
#include <math.h>

int main(void) {
    double amount, interest_rate, res;
    int years;

    printf("Amount deposited: ");
    scanf("%lf", &amount);

    printf("Interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Number of years: ");
    scanf("%d", &years);

    interest_rate /= 100;
    res = amount * exp(interest_rate * years);

    printf("Result: %f\n", res);

    return 0;
}
