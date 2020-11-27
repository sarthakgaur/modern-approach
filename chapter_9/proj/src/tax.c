#include <stdio.h>

float calc_tax(float income);

int main(void) {
    float income;
    printf("Enter the amount of taxable income: ");
    scanf("%f", &income);

    printf("Tax due: $%g\n", calc_tax(income));

    return 0;
}

float calc_tax(float income) {
    float tax = 0.00f;
    float temp;

    temp = income - 750 > 750 ? 750 : income;
    income -= temp;
    tax += 0.01f * temp;

    float rates[] = {0.02f, 0.03f, 0.04f, 0.05f, 0.06f};
    float fixed[] = {7.50f, 37.50f, 82.50f, 142.50f, 230.00f};

    int i = 0;

    while (income > 0) {
        temp = income - 1500 > 1500 ? 1500 : income;
        income -= temp;
        tax += rates[i] * temp + fixed[i];
        i++;
    }

    return tax;
}
