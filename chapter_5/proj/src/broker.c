/* Calculates a broker's commission */

#include <stdio.h>

int main(void) {
    int nshares;
    float commission1, commission2, pps, value;

    printf("Enter the number of shares: ");
    scanf("%d", &nshares);

    printf("Enter price per share: ");
    scanf("%f", &pps);

    // original broker's commission
    if (value < 2500.00f)
        commission1 = 30.00f + .017f * value;
    else if (value < 6250.00f)
        commission1 = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        commission1 = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        commission1 = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commission1 = 155.00f + .0011f * value;
    else
        commission1 = 255.00f + .0009f * value;

    if (commission1 < 39.00f)
        commission1 = 39.00f;

    // rival broker's commission
    if (nshares < 2000)
        commission2 = 33 + 0.03f * nshares;
    else
        commission2 = 33 + 0.02f * nshares;

    printf("Original broker's commission: $%.2f\n", commission1);
    printf("Rival broker's commission: $%.2f\n", commission2);

    return 0;
}
