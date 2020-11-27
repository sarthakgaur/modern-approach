#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#define QUEUE_SIZE 100

typedef struct {
    int contents[QUEUE_SIZE];
    int first_empty;
    int to_remove;
    int len;
} Queue;

void enqueue(Queue *q);
int dequeue(Queue *q);
int peek(Queue *q);
int peek_end(Queue *q);
bool is_empty(Queue *q);

#endif
