#include <stdio.h>
#include <stdarg.h>

char *max_pair(int num_pairs, ...);

int main(void) {
    char *str;

    str = max_pair(5, 180, "Seinfeld", 180, "I Love Lucy",
                39, "The Honeymooners", 210, "All in the Family",
                86, "The sopranos");

    printf("%s\n", str);

    return 0;
}

char *max_pair(int num_pairs, ...) {
    va_list al;
    int largest, i, n;
    char *pair_str, *str;

    va_start(al, num_pairs);

    largest = va_arg(al, int);
    pair_str = va_arg(al, char *);

    for (i = 1; i < num_pairs; i++) {
        n = va_arg(al, int);
        str = va_arg(al, char *);

        if (n > largest) {
            largest = n;
            pair_str = str;
        }
    }

    va_end(al);
    return pair_str;
}
