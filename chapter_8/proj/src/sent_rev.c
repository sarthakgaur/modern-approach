#include <stdio.h>

#define SIZE 500

int main(void) {
    char buffer[SIZE];
    char ch;
    int len = 0;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '.' && ch != '!' && ch != '?') {
        buffer[len] = ch;
        len++;
    }

    printf("Reversal of sentence: ");

    while (len >= 0) {
        int last = len - 1;
        int start = last;

        while (start >= 0 && buffer[start] != ' ')
            start--;

        // print the word
        for (int i = start + 1; i <= last; i++)
            putchar(buffer[i]);

        len = start;

        // print space if more words are left
        if (len > 0)
            putchar(' ');
    }

    printf("%c\n", ch); // print last char

    return 0;
}
