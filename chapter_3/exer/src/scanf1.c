#include <stdio.h>

int main(void) {
    int x, y, z;
    float a, b;

    printf("%%d-%%d-%%d: ");
    scanf("%d-%d-%d", &x, &y, &z);
    printf("%d-%d-%d\n", x, y, z);

    // printf("%%f : ");
    // scanf("%f ", &a);
    // printf("%f,%f\n", a, b);

    return 0;
}
