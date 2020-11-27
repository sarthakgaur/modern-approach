#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void write_upper(FILE *fp);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: write_upper file\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Error: can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    write_upper(fp);

    fclose(fp);

    return 0;
}

void write_upper(FILE *fp) {
    int ch;

    while ((ch = getc(fp)) != EOF) {
        if (isalpha(ch))
            putchar(toupper(ch));
        else
            putchar(ch);
    }
}
