#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

float eval_expr();
float calc(float n1, char op, float n2);

int main(void) {
    while (true) {
        printf("Enter an RPN expresson: ");
        float res = eval_expr();
        printf("Value of expression: %g\n", res);
    }

    return 0;
}

float eval_expr() {
    int res = 0;
    float n1, n2;
    char ch;

    while (true) {
        scanf(" %c", &ch);

        if (ch >= '0' && ch <= '9') {
            push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            n2 = pop();
            n1 = pop();
            res = calc(n1, ch, n2);
            push(res);
        } else if (ch == '=') {
            break;
        } else
            exit(EXIT_SUCCESS);
    }

    return res;
}

float calc(float n1, char op, float n2) {
    float res;

    switch (op) {
        case '+': res = n1 + n2;
                  break;
        case '-': res = n1 - n2;
                  break;
        case '*': res = n1 * n2;
                  break;
        case '/': res = n1 / n2;
                  break;
    }

    return res;
}
