#include <stdio.h>

int main(void) {
    int h, t, u;
    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &h, &t, &u);

    printf("The reversal is: %d%d%d\n", u, t, h);

    return 0;
}
