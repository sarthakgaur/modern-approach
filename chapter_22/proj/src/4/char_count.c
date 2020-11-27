#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count_chars(FILE *fp);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: char_count file\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    int ch_count;

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    ch_count = count_chars(fp);
    printf("Characters in %s: %d\n", argv[1], ch_count);

    fclose(fp);

    return 0;
}

int count_chars(FILE *fp) {
    int ch, count = 0;

    while ((ch = getc(fp)) != EOF)
        count++;

    return count;
}
