#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

#define QUEUE_SIZE 5

struct node {
    int value;
    struct node *next;
};

static struct node *first = NULL;
static struct node *last = NULL;

void terminate(char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void enqueue(int n) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = n;

    if (new_node == NULL)
        terminate("Error: queue full");

    if (first == NULL) {
        first = new_node;
        last = new_node;
    } else {
        last->next = new_node;
        last = last->next;
    }
}

int dequeue(void) {
    if (first == NULL)
        terminate("Error: queue empty");

    struct node *old_node = first;
    int value = old_node->value;

    first = first->next;
    free(old_node);
    return value;
}

int peek(void) {
    if (first == NULL)
        terminate("Error: queue empty");

    return first->value;
}

int peek_end(void) {
    if (last == NULL)
        terminate("Error: queue empty");

    return last->value;
}

bool is_empty(void) {
    return first == NULL;
}
