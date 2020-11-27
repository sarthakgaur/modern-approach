#include <stdio.h>

int main(void) {
    float res, num;
    int ch;

    printf("Enter an expression: ");
    scanf("%f", &res);

    while ((ch = getchar()) != '\n') {
        scanf("%f", &num);

        switch (ch) {
            case '+': res += num;
                      break;
            case '-': res -= num;
                      break;
            case '*': res *= num;
                      break;
            case '/': res /= num;
                      break;
        }
    }

    printf("Value of expression: %g\n", res);

    return 0;
}
