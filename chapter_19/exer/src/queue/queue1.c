#include "queue.h"

#define QUEUE_SIZE 5

static int queue[QUEUE_SIZE] = {0};

static int first_empty = 0;
static int to_remove = 0;
static int len = 0;

void enqueue(int n) {
    queue[first_empty++] = n;

    if (first_empty == QUEUE_SIZE)
        first_empty = 0;

    if (len != QUEUE_SIZE)
        len++;
}

int dequeue(void) {
    if (len == 0)
        return 0;

    int value = queue[to_remove++];

    if (to_remove == QUEUE_SIZE)
        to_remove = 0;

    len--;
    return value;
}

int peek(void) {
    return queue[to_remove];
}

int peek_end(void) {
    int index = first_empty - 1;

    if (index < 0)
        index = 0;

    return queue[index];
}

bool is_empty(void) {
    return len == 0;
}
