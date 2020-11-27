#include <stdio.h>

int main(void) {
    for (int i = 10; i > 0; i--) {
        if (i == 5)
            continue;
        printf("%d ", i);
    }

    printf("\n\n");

    for (int i = 10; i > 0; i--) {
        if (i == 5)
            goto inner;
        printf("%d ", i);
        inner: ;
    }

    printf("\n");

    return 0;
}
