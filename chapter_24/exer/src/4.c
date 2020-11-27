#include <stdio.h>

#define TRY_MATH_FCN(fn, x) (try_math_fcn(fn, x, "Error in call of " #fn))

int main(void) {
    return 0;
}

double try_math_fcn((double) (*fn) (double), double val, const char *str) {
    double res;

    errno = 0;
    res = fn(val);
    if (errno != 0) {
        perror(str);
        exit(EXIT_FAILURE);
    }

    return res;
}
