#include <stdio.h>

int main(void) {
    float income;
    printf("Enter the amount of taxable income: ");
    scanf("%f", &income);

    float tax = 0.00f;
    float temp;

    temp = income - 750 > 750 ? 750 : income;
    income -= temp;
    tax += 0.01f * temp;

    if (income) {
        temp = income - 1500 > 1500 ? 1500 : income;
        income -= temp;
        tax += 0.02f * temp + 7.50f;
    }

    if (income) {
        temp = income - 1500 > 1500 ? 1500 : income;
        income -= temp;
        tax += 0.03f * temp + 37.50f;
    }

    if (income) {
        temp = income - 1500 > 1500 ? 1500 : income;
        income -= temp;
        tax += 0.04f * temp + 82.50f;
    }

    if (income) {
        temp = income - 1750 > 1750 ? 1750 : income;
        income -= temp;
        tax += 0.05f * temp + 142.50f;
    }
    
    if (income) {
        tax += 0.06f * income + 230.00f;
    }

    printf("Tax due: $%f\n", tax);

    return 0;
}
