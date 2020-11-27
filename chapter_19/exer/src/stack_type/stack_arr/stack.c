#include "stdio.h"
#include "stdlib.h"
#include "stack.h"
#define STACK_SIZE 10

struct stack_type {
    Item contents[STACK_SIZE];
    int top;
};

static void terminate(char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(void) {
    Stack new_stack = malloc(sizeof(struct stack_type));
    if (new_stack == NULL)
        terminate("Error: stack is full.");
    new_stack->top = 0; // forgot to set top
    return new_stack;
}

void destroy(Stack s) {
    free(s);
}

void push(Stack s, Item i) {
    if (is_full(s))
        terminate("Error: Stack is full.");
    s->contents[s->top++] = i;
}

Item pop(Stack s) {
    if (is_empty(s))
        terminate("Error: Stack is empty.");
    return s->contents[--s->top];
}

void make_empty(Stacks s) {
    s->top = 0;
}

bool is_full(Stack s) {
    return s->top == STACK_SIZE;
}

bool is_empty(Stack s) {
    return s->top == 0;
}
