#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 50
#define CAP 200

void get_expr(char expr[], int n);
float evaluate_RPN_expression(const char *expression);
float calc(float n1, char op, float n2);
void stack_overflow(void);
void stack_underflow(void);

int main(void) {
    char expr[CAP+1];
    float res;

    while (true) {
        printf("Enter an RPN expresson: ");
        get_expr(expr, CAP);
        res = evaluate_RPN_expression(expr);
        printf("Value of expression: %g\n", res);
    }

    return 0;
}

void get_expr(char expr[], int n) {
    char ch;
    while ((ch = getchar()) != '\n' && expr < expr + n)
        *expr++ = ch;
    *expr = '\0';
}

float evaluate_RPN_expression(const char *expression) {
    float token_arr[SIZE], res = 0;
    float n1, n2;
    int i = 0;
    char ch;

    while (*expression) {
        ch = *expression++;

        if (i >= SIZE)
            stack_overflow();

        if (ch == ' ')
            continue;
        else if (ch >= '0' && ch <= '9') {
            token_arr[i] = ch - '0';
            i++;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (i >= 2) {
                n1 = token_arr[i - 2];
                n2 = token_arr[i - 1];
                res = calc(n1, ch, n2);
                token_arr[i - 2] = res;
                i--;
            } else
                stack_underflow();
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

void stack_overflow(void) {
    printf("Expression is too complex.\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("Not enough operand in expression.\n");
    exit(EXIT_FAILURE);
}
