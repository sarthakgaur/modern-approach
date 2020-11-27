#include <stdio.h>

int main(void) {
    int wind;
    printf("Enter wind force: ");
    scanf("%d", &wind);

    if (wind < 1)
        printf("Calm");
    else if (wind < 4)
        printf("Light air");
    else if (wind < 28)
        printf("Breeze");
    else if (wind < 48)
        printf("Gale");
    else if (wind < 64)
        printf("Storm");
    else
        printf("Hurricane");

    printf("\n");

    return 0 ;
}
