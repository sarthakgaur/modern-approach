#include <stdio.h>
#include "stack.h"

int main(void) {
    Stack s1 = create();

    printf("is empty: %d\n", is_empty(s1));

    for (int i = 0; i < 10; i++) {
        push(s1, i);
    }

    printf("is full: %d\n", is_full(s1));

    for (int i = 0; i < 10; i++) {
        printf("value: %d\n", pop(s1));
    }

    printf("is empty: %d\n", is_empty(s1));
    destroy(s1);

    return 0;
}
