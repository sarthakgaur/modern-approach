#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct queue_type {
    Item *contents;
    int first_empty;
    int to_remove;
    int len;
    int size;
};

static void terminate(char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(int size) {
    Queue new_queue = malloc(sizeof(struct queue_type)); // forgot malloc check
    if (new_queue == NULL)
        terminate("Error: queue creation failed");

    new_queue->contents = malloc(size * sizeof(Item));
    if (new_queue->contents == NULL)
        terminate("Error: queue creation failed");

    new_queue->first_empty = 0;
    new_queue->to_remove = 0;
    new_queue->len = 0;
    new_queue->size = size;

    return new_queue;
}

void destroy(Queue q) {
    free(q->contents);
    free(q);
}

void enqueue(Queue q, Item i) {
    if (is_full(q))
        terminate("Error: queue is full");

    if (q->first_empty == q->size)
        q->first_empty = 0;

    q->contents[q->first_empty++] = i;
    q->len++;
}

Item dequeue(Queue q) {
    if (is_empty(q))
        terminate("Error: queue is empty");

    Item data = q->contents[q->to_remove++];
    q->len--;

    if (q->to_remove == q->size)
        q->to_remove = 0;

    return data;
}

Item peek(Queue q) {
    if (is_empty(q))
        terminate("Error: queue is empty");

    return q->contents[q->to_remove];
}

Item peek_last(Queue q) {
    if (is_empty(q))
        terminate("Error: queue is empty");

    return q->contents[q->first_empty - 1];
}

void make_empty(Queue q) {
    q->first_empty = 0;
    q->to_remove = 0;
    q->len = 0;
}

bool is_empty(Queue q) {
    return q->len == 0;
}

bool is_full(Queue q) {
    return q->len == q->size;
}
