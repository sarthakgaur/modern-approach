#include <stdio.h>

int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%4d", &n);

    if (n > 999)
        printf("The number %d has 4 digits\n", n);
    else if (n > 99)
        printf("The number %d has 3 digits\n", n);
    else if (n > 9)
        printf("The number %d has 2 digits\n", n);
    else
        printf("The number %d has 1 digit\n", n);

    return 0;
}
