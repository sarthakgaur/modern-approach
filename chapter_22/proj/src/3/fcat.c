#include <stdio.h>
#include <stdlib.h>

void write_file(FILE *fp);

int main(int argc, char *argv[]) {
    // always write error message to stderr

    if (argc < 2) {
        fprintf(stderr, "usage: fcat file1 file2 file3 ...\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;

    for (int i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            fprintf(stderr, "Error: cannot open %s\n", argv[i]);
            exit(EXIT_FAILURE);
        } else {
            write_file(fp);
            fclose(fp);
        }
    }

    return 0;
}

void write_file(FILE *fp) {
    int ch;

    while ((ch = getc(fp)) != EOF)
        putchar(ch);
}
