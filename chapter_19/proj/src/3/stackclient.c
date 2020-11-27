#include <stdio.h>
#include "stackADT.h"

int main(void) {
    Stack stack = create();

    for (int i = 0; i < 10; i++)
        push(stack, i);

    pop(stack);
    printf("len: %d\n", length(stack));

    return 0;
}
