#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define EXT_LEN 4

bool is_valid_file(const char *filename);
char *gen_filename(const char *old_filename);
void write_uncompressed(FILE *compf, FILE *uncompf);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: compress_file file\n");
        exit(EXIT_FAILURE);
    }

    if (!is_valid_file(argv[1])) {
        fprintf(stderr, "Error: %s is not in .rle format\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *compf, *uncompf;

    if ((compf = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char *uncom_filename = gen_filename(argv[1]);

    if ((uncompf = fopen(uncom_filename, "wb")) == NULL) {
        fprintf(stderr, "Error: uncompressed file %s could not be created\n", uncom_filename);
        fclose(compf);
        exit(EXIT_FAILURE);
    }

    write_uncompressed(compf, uncompf);

    // close the streams and free the filename
    fclose(compf);
    fclose(uncompf);
    free(uncom_filename);

    return 0;
}

bool is_valid_file(const char *filename) {
    const char *valid_ext = ".rle";

    int file_len = strlen(filename);

    if (file_len < EXT_LEN)
        return false;

    int ext_offset = file_len - EXT_LEN;

    return strcmp(filename + ext_offset, valid_ext) == 0; 
}

char *gen_filename(const char *old_filename) {
    int old_filename_len = strlen(old_filename);

    char *new_filename = malloc(old_filename_len - EXT_LEN + 1);

    if (new_filename == NULL) {
        fprintf(stderr, "Error: malloc failed in gen_filename\n");
        exit(EXIT_FAILURE);
    }

    int ext_offset = old_filename_len - EXT_LEN;

    strncpy(new_filename, old_filename, ext_offset);
    new_filename[ext_offset] = '\0';

    return new_filename;
}

void write_uncompressed(FILE *compf, FILE *uncompf) {
    int current_byte, byte_rep;
    bool byte_rep_read = false;

    while ((current_byte = getc(compf)) != EOF) {
        if (!byte_rep_read) {
            byte_rep = current_byte;
            byte_rep_read = true;
        } else {
            while (byte_rep--)
                putc(current_byte, uncompf);
            byte_rep_read = false;
        }
    }
}
