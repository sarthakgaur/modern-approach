#include <stdio.h>

union float_wrapper {
    float f;
    struct {
        unsigned int fraction: 23;
        unsigned int exponent: 8;
        unsigned int sign: 1;
    } float_parts;
};

int main(void) {
    union float_wrapper fw;

    fw.float_parts.sign = 1;
    fw.float_parts.exponent = 128;
    fw.float_parts.fraction = 0;

    printf("value: %f\n", fw.f);

    return 0;
}
