#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FN_SIZE 100
#define EXT_LEN 4

void read_line(char *buffer, int size);
char *gen_filename(const char *old_filename);
void write_shifted(FILE *sourcef, FILE *destf, int shift);

int main(void) {
    char filename[FN_SIZE + 1];
    int shift;

    printf("Enter name of file to be encrypted: ");
    read_line(filename, sizeof(filename));

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    FILE *sourcef = fopen(filename, "r");

    if (sourcef == NULL) {
        fprintf(stderr, "Error: file %s could not be opened\n", filename);
        exit(EXIT_FAILURE);
    }

    char *new_filename = gen_filename(filename);

    FILE *destf = fopen(new_filename, "w");

    if (destf == NULL) {
        fprintf(stderr, "Error: file %s could not be opened for writing\n", filename);
        fclose(sourcef);
        free(new_filename);
        exit(EXIT_FAILURE);
    }

    write_shifted(sourcef, destf, shift);

    fclose(sourcef);
    fclose(destf);
    free(new_filename);

    return 0;
}

void read_line(char *buffer, int size) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n' && ch != EOF && i < size) 
        buffer[i++] = ch;

    buffer[i] = '\0';
}

char *gen_filename(const char *old_filename) {
    char *ext = ".enc";

    char *new_filename = malloc(strlen(old_filename) + EXT_LEN + 1);

    if (new_filename == NULL) {
        fprintf(stderr, "Error: malloc failed in gen_filename\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_filename, old_filename);
    strcat(new_filename, ext);

    return new_filename;
}

void write_shifted(FILE *sourcef, FILE *destf, int shift) {
    int ch, upper_ch;

    while ((ch = getc(sourcef)) != EOF) {
        upper_ch = toupper(ch);

        if (isalpha(upper_ch)) {
            if (ch == upper_ch)
                ch = (ch - 'A' + shift) % 26 + 'A';
            else
                ch = (ch - 'a' + shift) % 26 + 'a';
        }

        putc(ch, destf);
    }
}
