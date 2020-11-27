#include <stdio.h>
#include "word.h"

int read_char(FILE *sourcef) {
    int ch = getc(sourcef);

    if (ch == '\n' || ch == '\t')
        return ' ';
    return ch;
}

void read_word(char *word, int len, FILE *sourcef) {
    int ch, pos = 0;

    while ((ch = read_char(sourcef)) == ' ')
        ;
    while (ch != ' ' && ch != EOF) {
        if (pos < len)
            word[pos++] = ch;
        ch = read_char(sourcef);
    }
    word[pos] = '\0';
}
