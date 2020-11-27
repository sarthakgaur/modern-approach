#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external veriables */
int stack[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

void stack_overflow(void);
void stack_underflow(void);

int main(void) {
    printf("Enter parenthese and/or braces: ");

    char ch;

    while ((ch = getchar()) != '\n') {
        if (ch == '(' || ch == '{')
            push(ch);
        else if (ch == ')' || ch == '}') {
            char top = pop();

            if ((ch == ')' && top != '(')
                    || (ch == '}' && top != '{')) {
                printf("Parentheses/braces are not nested properly\n");
                return 0;
            }
        }
    }

    if (top == 0)
        printf("Parentheses/braces are nested properly\n");
    else
        printf("Parentheses/braces are not nested properly\n");

    return 0;
}

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(int i) {
    if (is_full())
        stack_overflow();
    else
        stack[top++] = i;
}

int pop(void) {
    if (is_empty())
        stack_underflow();
    else
        return stack[--top];
}

void stack_overflow(void) {
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
}
