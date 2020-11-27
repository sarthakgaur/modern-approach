#include <stdio.h>

int main(void) {
    printf("Size of types in bytes:\n");

    printf("int: %zu\n", sizeof(int));
    printf("short: %zu\n", sizeof(short));
    printf("long: %zu\n", sizeof(long));
    printf("float: %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));
    printf("long double: %zu\n", sizeof(long double));

    return 0;
}
