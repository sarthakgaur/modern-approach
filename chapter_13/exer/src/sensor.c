#include <stdio.h>

#define SIZE 100

void sensor(char str[]);

int main(void) {
    char buffer[SIZE], ch;
    int i;

    printf("Enter a string: ");

    while ((ch = getchar()) != '\n' && i < SIZE) {
        buffer[i] = ch;
        i++;
    }
    buffer[i] = '\0';

    sensor(buffer);

    printf("%s\n", buffer);

    return 0;
}

void sensor(char str[]) {
    int state = 0;
    char *start;
    char *p = str;

    while (*p != '\0') {
        if (*p == 'f' && state == 0) {
            state = 1;
            start = p;
        } else if (*p == 'o' && state == 1)
            state = 2;
        else if (*p == 'o' && state == 2)
            state = 3;
        else
            state = 0;

        if (state == 3) {
            state = 0;
            while (start <= p)
                *start++ = 'x';
        }

        p++;
    }
}
