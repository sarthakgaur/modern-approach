#include "stdio.h"
#include "stdlib.h"
#include "stack.h"

struct node {
    Item data;
    struct node *next;
};

struct stack_type {
    struct node *top;
};

static void terminate(char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(void) {
    Stack new_stack = malloc(sizeof(struct stack_type));
    if (new_stack == NULL)
        terminate("Error: stack could not be created.");

    new_stack->top = NULL;
    return new_stack;
}

void destroy(Stack s) {
    while (!is_empty(s))
        pop(s);
    
    free(s);
}

void push(Stack s, Item i) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error: stack is full.");

    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
}

Item pop(Stack s) {
    if (is_empty(s))
        terminate("Error: Stack is empty.");

    struct node *old_node = s->top;
    Item data = old_node->data;
    s->top = old_node->next;
    free(old_node);
    return data;
}

void make_empty(Stacks s) {
    while (!is_empty(s))
        pop(s);
}

bool is_full(Stack s) {
    return false;
}

bool is_empty(Stack s) {
    return s->top == NULL;
}
