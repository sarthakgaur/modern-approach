#include <stdio.h>

int main(int argc, char *argv[]) {
    char **p = &argv[0] + argc - 1;

    while (p > &argv[0])
        printf("%s ", *p--);

    printf("\n");
    return 0;
}
