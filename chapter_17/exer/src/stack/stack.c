#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

struct node {
    int value;
    struct node *next;
};

/* external veriables */
struct node *top = NULL;

int main(void) {
    return 0;
}

void make_empty(void) {
    struct node *temp;

    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

bool is_empty(void) {
    return top == NULL;
}

bool push(int i) {
    struct node *cur;
    cur = malloc(sizeof(struct node));

    if (cur == NULL)
        return false;

    cur->value = i;
    cur->next = top;
    top = cur;

    return true;
}

int pop(void) {
    int i = 0;

    // should have exited the program
    if (top == NULL) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }

    i = top->value;

    struct node *temp = top;
    top = top->next;
    free(temp);

    return i;
}
