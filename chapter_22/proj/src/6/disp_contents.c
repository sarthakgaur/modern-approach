#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define BUF_SIZE 10

void display_contents(FILE *fp);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: word_count file\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    display_contents(fp);

    fclose(fp);

    return 0;
}

void display_contents(FILE *fp) {
    printf("Offset             Bytes               Characters\n");
    printf("------  -----------------------------  ----------\n");

    int offset = 0;
    int buffer[BUF_SIZE], ch, i, j;

    bool eof_reached = false;

    while (!eof_reached) {
        // print the offset
        printf("%6d", offset);
        printf("  ");

        // read chars till the EOF or if BUF_SIZE is reached
        // set eof_reached flag to terminate after this iteration
        i = 0;
        while (i < BUF_SIZE && (ch = getc(fp)) != EOF)
            buffer[i++] = ch;
        if (ch == EOF)
            eof_reached = true;

        // print the bytes in hex
        for (j = 0; j < i; j++)
            printf("%.2X ", buffer[j]);

        // print three space if bytes not present
        for (; j < BUF_SIZE; j++)
            printf("   ");

        printf(" ");

        // print '.' is element is not printable
        for (j = 0; j < i; j++)
            if (isprint(buffer[j]))
                printf("%c", buffer[j]);
            else
                printf(".");
        printf("\n");

        offset += BUF_SIZE;
    }
}
