#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

void printdf(char *fmt, ...);
void print_int(int n);
void print_str(char *str);

int main(void) {
    printdf("%i%i%i%%str %d char %d int %d double %d %a %c\n", -23, 91, 51, 41, "str");
    return 0;
}

void printdf(char *fmt, ...) {
    va_list ap;
    char ch;
    int i = 0;
    bool conv_start = false;

    va_start(ap, fmt);

    while ((ch = fmt[i]) != '\0') {
        if (!conv_start && ch == '%') {
            conv_start = true;
        } else if (conv_start && ch == 'd') {
            print_int(va_arg(ap, int));
            conv_start = false;
        } else if (conv_start && ch == 'c') {
            print_str(va_arg(ap, char *));
            conv_start = false;
        } else if (conv_start) {
            conv_start = false;
        } else {
            putchar(ch);
        }
        i++;
    }

    va_end(ap);
}

void print_int(int n) {
    char buffer[25];
    int i = 0;

    if (n < 0) {
        putchar('-');
        n *= -1;
    }

    while (n != 0) {
        buffer[i++] = '0' + (n % 10);
        n /= 10;
    }
    i--;

    while (i >= 0)
        putchar(buffer[i--]);
}

void print_str(char *str) {
    while (*str)
        putchar(*str++);
}
