#include <stdio.h>

int main(void)
{
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);

    // int res = 3 * x * x * x * x * x;
    // res = res + (2 * x * x * x * x);
    // res = res - (5 * x * x * x);
    // res = res - (x * x);
    // res = res + (7 * x);
    // res = res - 6;

    int res = 3 * x + 2;
    res = res * x - 5;
    res = res * x - 1;
    res = res * x + 7;
    res = res * x - 6;

    printf("Result: %d\n", res);

    return 0;
}
