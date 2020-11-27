#include <stdio.h>

int main(void) {
    float max, input;

    max = 0;

     do {
        printf("Enter a number: ");
        scanf("%f", &input);

        if (input > max)
            max = input;
    } while (input > 0);

    printf("\nThe largest number entered was: %.2f\n", max);

    return 0;
}
