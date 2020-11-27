#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int line_count(FILE *fp);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: word_count file\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    int ln_count;

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    ln_count = line_count(fp);
    printf("lines in %s: %d\n", argv[1], ln_count);

    fclose(fp);

    return 0;
}

int line_count(FILE *fp) {
    int ch, count = 0;

    while ((ch = getc(fp)) != EOF)
        if (ch == '\n')
            count++;

    return count;
}
