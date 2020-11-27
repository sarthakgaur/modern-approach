#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator,
        int *reduced_denominator);

int main(void) {
    int n, d, rn, rd;

    printf("Enter a fraction: ");
    scanf("%d /%d", &n, &d);

    reduce(n, d, &rn, &rd);

    printf("In lowest terms: %d/%d\n", rn, rd);

    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator,
        int *reduced_denominator) {
    int tn = numerator;
    int td = denominator;
    int r;

    while (td != 0) {
        r = tn % td;
        tn = td;
        td = r;
    }

    *reduced_numerator = numerator / tn;
    *reduced_denominator = denominator / tn;
}
