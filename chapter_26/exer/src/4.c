#include <stdio.h>
#include <stdarg.h>

void display(int n, ...);

int main(void) {
    display(4, "Special", "Agent", "Dale", "Cooper");
    return 0;
}

void display(int n, ...) {
    va_list val;
    char *str;

    va_start(val, n);

    while (n-- > 0) {
        str = va_arg(val, char *);
        while (*str)
            putchar(*str++);
        if (n > 0)
            putchar(' ');
    }
    putchar('\n');

    va_end(val);
}
