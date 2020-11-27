#include <stdio.h>
#include <ctype.h>

int main(void) {
    int h, m;
    char meri; // meridiem

    printf("Enter a 12-hour time: ");
    scanf("%d :%d %c", &h, &m, &meri);

    meri = toupper(meri);

    int adj = meri == 'P' ? 12 : 0; // adjustment to the time if 'P'

    h = h == 12 ? 0 : h; // make 12 hour to 0
    h += adj;

    printf("Equivalent 24-hour time: %.2d:%.2d\n", h, m);

    return 0;
}
