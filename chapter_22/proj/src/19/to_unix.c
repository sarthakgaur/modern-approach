#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: to_unix win_file unix_file\n");
        exit(EXIT_FAILURE);
    }

    FILE *source_fp, *dest_fp;

    source_fp = fopen(argv[1], "rb");

    if (source_fp == NULL) {
        fprintf(stderr, "Error: %s could not be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    dest_fp = fopen(argv[2], "wb");

    if (source_fp == NULL) {
        fprintf(stderr, "Error: %s could not be opened\n", argv[2]);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    to_unix(source_fp, dest_fp);

    fclose(source_fp);
    fclose(dest_fp);

    return 0;
}

void to_unix(FILE *source_fp, FILE *dest_fp) {
    int ch;

    while ((ch = getc(source_fp)) != EOF)
        if (ch != '\r')
            putc(ch, dest_fp);
}
