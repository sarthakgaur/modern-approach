#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define SIZE 100

int ishex(char *str);

int main(void) {
    char str[SIZE];
    int res;

    printf("Enter a hex number: ");
    fgets(str, sizeof(str), stdin);

    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';

    res = ishex(str);
    printf("res: %d\n", res);

    return 0;
}

int ishex(char *str) {
    int n = 0, ch, i = 0;

    int len = strlen(str);
    
    while ((ch = str[i]) != '\0') {
        ch = tolower(ch);

        if (isdigit(ch))
            n += (ch - '0') * (int) pow(16, len - (i + 1));
        else if (isxdigit(ch))
            n += (ch - 'a' + 10) * (int) pow(16, len - (i + 1));
        else
            return -1;

        i++;
    }

    return n;
}
