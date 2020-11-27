/* Copies a file */

#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 100

int main(int argc, char *argv[]) {
    FILE *source_fp, *dest_fp;
    char buffer[BLOCK_SIZE];
    int read_count;
    int write_count;

    if (argc != 3) {
        fprintf(stderr, "usage: fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    while ((read_count = fread(buffer, sizeof(buffer[0]), BLOCK_SIZE, source_fp)) != 0) {
        if (ferror(source_fp)) {
            fprintf(stderr, "read operation failed on %s file\n", argv[1]);
            fclose(source_fp);
            fclose(dest_fp);
            exit(EXIT_FAILURE);
        }

        write_count = fwrite(buffer, sizeof(buffer[0]), read_count, dest_fp);

        if (write_count != read_count) {
            fprintf(stderr, "write operation failed on %s file\n", argv[2]);
            fclose(source_fp);
            fclose(dest_fp);
            exit(EXIT_FAILURE);
        }
    }

    fclose(source_fp);
    fclose(dest_fp);
    return 0;
}
