#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char **p;
    int sum = 0;

    for (p = &argv[1]; *p != NULL; p++)
        sum += atoi(*p);

    printf("Total: %d\n", sum);

    return 0;
}
