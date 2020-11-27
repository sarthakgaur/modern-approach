#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int word_count(FILE *fp);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: word_count file\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    int wd_count;

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    wd_count = word_count(fp);
    printf("Words in %s: %d\n", argv[1], wd_count);

    fclose(fp);

    return 0;
}

int word_count(FILE *fp) {
    int ch, count = 0;
    bool in_word = false;

    while ((ch = getc(fp)) != EOF) {
        if (!isspace(ch))
            in_word = true;
        else if (in_word == true) {
            in_word = false;
            count++;
        }
    }

    return count;
}
