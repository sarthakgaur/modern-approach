/* Performs XOR encryption */

#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

void write_encrypt(FILE *sourcef, FILE *destf);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: xor source dest\n");
        exit(EXIT_FAILURE);
    }

    FILE *sourcef, *destf;

    if ((sourcef = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((destf = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", argv[2]);
        fclose(sourcef);
        exit(EXIT_FAILURE);
    }

    write_encrypt(sourcef, destf);

    fclose(sourcef);
    fclose(destf);

    return 0;
}

void write_encrypt(FILE *sourcef, FILE *destf) {
    int orig_char, new_char;

    while ((orig_char = getc(sourcef)) != EOF) {
        new_char = orig_char ^ KEY;
        putc(new_char, destf);
    }
}
