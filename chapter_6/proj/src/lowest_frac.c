#include <stdio.h>

int main(void) {
    int n, d;

    printf("Enter a fraction: ");
    scanf("%d /%d", &n, &d);

    int tn = n;
    int td = d;
    int r;

    while (td != 0) {
        r = tn % td;
        tn = td;
        td = r;
    }

    n = n / tn;
    d = d / tn;

    printf("In lowest terms: %d/%d\n", n, d);

    return 0;
}
