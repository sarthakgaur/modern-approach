#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void) {
    printf("Enter parenthese and/or braces: ");

    char ch;
    Stack stack = create();

    while ((ch = getchar()) != '\n') {
        if (ch == '(' || ch == '{')
            push(stack, ch);
        else if (ch == ')' || ch == '}') {
            char top = pop(stack);

            if ((ch == ')' && top != '(')
                    || (ch == '}' && top != '{')) {
                printf("Parentheses/braces are not nested properly\n");
                return 0;
            }
        }
    }

    if (is_empty(stack))
        printf("Parentheses/braces are nested properly\n");
    else
        printf("Parentheses/braces are not nested properly\n");

    return 0;
}
