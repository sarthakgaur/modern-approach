#include <stdio.h>
#include <stdarg.h>

int max_int(int n, ...);

int main(void) {
    int res;

    res = max_int(7, 11, 23, 39, 92, 22, 11, 0);
    printf("%d\n", res);

    return 0;
}

int max_int(int n, ...) {
    va_list ap;
    int current, largest;

    va_start(ap, n);
    largest = n;

    while ((current = va_arg(ap, int)) != 0)
        if (current > largest)
            largest = current;

    va_end(ap);
    return largest;
}

