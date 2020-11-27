/* Formats a file of text */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

void justify(FILE *sourcef, FILE *destf);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: justify input output\n");
        exit(EXIT_FAILURE);
    }

    FILE *sourcef, *destf;

    sourcef = fopen(argv[1], "r");

    if (sourcef == NULL) {
        fprintf(stderr, "Error: file %s could not be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    destf = fopen(argv[2], "w");

    if (destf == NULL) {
        fprintf(stderr, "Error: file %s could not be opened\n", argv[2]);
        fclose(sourcef);
        exit(EXIT_FAILURE);
    }

    justify(sourcef, destf);

    fclose(sourcef);
    fclose(destf);

    return 0;
}

void justify(FILE *sourcef, FILE *destf) {
    char word[MAX_WORD_LEN+2];
    int word_len;

    clear_line();
    for (;;) {
        read_word(word, MAX_WORD_LEN+1, sourcef);
        word_len = strlen(word);
        if (word_len == 0) {
            flush_line(destf);
            return;
        }
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        if (word_len + 1 > space_remaining()) {
            write_line(destf);
            clear_line();
        }
        add_word(word);
    }
}
