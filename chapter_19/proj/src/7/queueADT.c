#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *first;
    struct node *last;
};

static void terminate(char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(void) {
    Queue new_queue = malloc(sizeof(struct queue_type)); // forgot malloc check
    if (new_queue == NULL)
        terminate("Error: queue creation failed");

    new_queue->first = NULL;
    new_queue->last = NULL;
    return new_queue;
}

void destroy(Queue q) {
    make_empty(q);
    free(q);
}

void enqueue(Queue q, Item i) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error: queue is full");

    new_node->data = i;
    new_node->next = NULL;

    if (q->first == NULL) {
        q->first = q->last = new_node;
    } else {
        q->last->next = new_node;
        q->last = new_node;
    }
}

Item dequeue(Queue q) {
    if (is_empty(q))
        terminate("Error: queue is empty");

    struct node *first_node = q->first;
    Item data = first_node->data;

    // forgot to set the first and last pointer to null if they are pointing
    // to the same node
    if (q->first == q->last)
        q->first = q->last = NULL;
    else
        q->first = first_node->next;

    free(first_node);

    return data;
}

Item peek(Queue q) {
    if (is_empty(q))
        terminate("Error: queue is empty");

    return q->first->data;
}

Item peek_last(Queue q) {
    if (is_empty(q))
        terminate("Error: queue is empty");

    return q->last->data;
}

void make_empty(Queue q) {
    while (!is_empty(q))
        dequeue(q);
}

bool is_empty(Queue q) {
    return q->first == NULL;
}

bool is_full(Queue q) {
    return false;
}
