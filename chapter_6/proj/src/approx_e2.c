#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    float e = 1.00f;
    int d = 1;

    for (int i = 1; true; i++) {
        d *= i;

        float cf = 1.00f / d;
        if (cf < n)
            break;

        e += cf;
    }


    printf("Result: %f\n", e);

    return 0;
}
