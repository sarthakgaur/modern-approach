#include <stdio.h>
#include "queue.h"

int main(void) {
    int n;

    for (int i = 1; i < 7; i++)
        enqueue(i);

    for (int i = 1; i < 7; i++) {
        n = dequeue();
        printf("dequeue value: %d\n", n);
    }

    return 0;
}
