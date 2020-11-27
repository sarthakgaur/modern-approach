#include <stdio.h>

#define SIZE 500

int main(void) {
    char buffer[SIZE];
    char *p = buffer;
    char *last, *start;
    char ch;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '.' && ch != '!' && ch != '?') {
        *p++ = ch;
    }

    printf("Reversal of sentence: ");

    while (p >= buffer) {
        p--;
        last = p;

        while (p >= buffer && *p != ' ')
            p--;

        // print the word
        for (char *c = p + 1; c <= last; c++)
            putchar(*c);

        // print space if more words are left
        if (p > buffer)
            putchar(' ');
    }

    printf("%c\n", ch); // print last char

    return 0;
}
