#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

bool isident(char *str);

int main(void) {
    char str[SIZE];
    bool res;

    printf("Enter a identifier: ");
    fgets(str, sizeof(str), stdin);

    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

    res = isident(str);
    printf("res: %d\n", res);

    return 0;
}

bool isident(char *str) {
    char ch;
    int i = 0;

    while ((ch = str[i]) != '\0') {
        if (i == 0 && isdigit(ch))
            return false;
        else if (!(isdigit(ch) || isalpha(ch) || ch == '_'))
            return false;
        i++;
    }

    return true;
}
