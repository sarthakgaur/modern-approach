#include <stdio.h>

void to_win(FILE *source_fp, FILE *dest_fp);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: to_win unix_file win_file\n");
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

    to_win(source_fp, dest_fp);

    fclose(source_fp);
    fclose(dest_fp);

    return 0;
}

void to_win(FILE *source_fp, FILE *dest_fp) {
    int ch;

    while ((ch = getc(source_fp)) != EOF) {
        if (ch == '\n')
            putc('\r', dest_fp);
        putc(ch, dest_fp);
    }
}
