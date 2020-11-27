#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int count_words(char *str);

int main(void) {
    char str[SIZE];
    int len;

    printf("Enter a str: ");
    fgets(str, sizeof(str), stdin);

    len = count_words(str);
    printf("len: %d\n", len);

    return 0;
}

int count_words(char *str) {
    char *p;
    int words = 0;

    // any non-white space characters
    p = strtok(str, " \t\r\v\n\f");

    if (p == NULL)
        return 0;

    do {
        words++;
    } while (strtok(NULL, " \t\r\v\n\f"));

    return words;
}
