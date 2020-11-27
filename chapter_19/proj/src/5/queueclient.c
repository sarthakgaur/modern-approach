#include <stdio.h>
#include "queueADT.h"

int main(void) {
    Queue q1 = create();

    printf("is_full: %d\n", is_full(q1));
    printf("is_empty: %d\n\n", is_empty(q1));

    for (int i = 0; i < 10; i++)
        enqueue(q1, i + 1);

    printf("peek: %d\n", peek(q1));
    printf("peek_last: %d\n\n", peek_last(q1));

    printf("is_full: %d\n", is_full(q1));
    printf("is_empty: %d\n\n", is_empty(q1));

    for (int i = 0; i < 10; i++)
        printf("value: %d\n", dequeue(q1));

    printf("\nis_full: %d\n", is_full(q1));
    printf("is_empty: %d\n", is_empty(q1));

    return 0;
}
