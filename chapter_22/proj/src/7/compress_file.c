#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define EXT_LEN 4

char *gen_filename(const char *old_filename);
void write_compressed(FILE *sourcef, FILE *compf);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: compress_file file\n");
        exit(EXIT_FAILURE);
    }

    FILE *sourcef, *compf;

    if ((sourcef = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *com_filename = gen_filename(argv[1]);

    if ((compf = fopen(com_filename, "wb")) == NULL) {
        fprintf(stderr, "Error: compressed file %s could not be created\n", argv[1]);
        fclose(sourcef);
        exit(EXIT_FAILURE);
    }

    write_compressed(sourcef, compf);

    // close the streams and free the filename
    fclose(sourcef);
    fclose(compf);
    free(com_filename);

    return 0;
}

char *gen_filename(const char *old_filename) {
    char *new_filename = malloc(strlen(old_filename) + EXT_LEN + 1);

    if (new_filename == NULL) {
        fprintf(stderr, "Error: malloc failed in gen_filename\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_filename, old_filename);
    strcat(new_filename, ".rle");

    return new_filename;
}

void write_compressed(FILE *sourcef, FILE *compf) {
    int old_byte, current_byte, byte_rep = 1;
    bool old_byte_set = false, byte_read = false;

    while ((current_byte = getc(sourcef)) != EOF) {
        byte_read = true;

        if (!old_byte_set) {
            old_byte = current_byte;
            old_byte_set = true;
        } else if (old_byte == current_byte) {
            byte_rep++;
        } else if (old_byte != current_byte) {
            putc(byte_rep, compf);
            putc(old_byte, compf);
            byte_rep = 1;
            old_byte = current_byte;
        }
    }

    if (byte_read) {
        putc(byte_rep, compf);
        putc(old_byte, compf);
    }
}
