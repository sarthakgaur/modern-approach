#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_FIELD_WIDTH 4
#define MAX_FIELDS 3

void controller(FILE *fp);
int to_num(char buffer[]);
void write_fmt_phone(int fields[]);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: fmt_phone file\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "Error: failed to open %s\n", argv[1]); 
        exit(EXIT_FAILURE);
    }

    controller(fp);

    fclose(fp);

    return 0;
}

void controller(FILE *fp) {
    int ch, fields[MAX_FIELDS], fields_read = 0, digit_read = 0;
    int mark = 3;
    char buffer[MAX_FIELD_WIDTH + 1];

    while ((ch = getc(fp)) != EOF) {
        if (isdigit(ch)) {
            buffer[digit_read++] = ch;

            if (digit_read == mark) {
                buffer[digit_read] = '\0';
                fields[fields_read++] = to_num(buffer);
                mark = fields_read < 2 ? 3 : 4;
                digit_read = 0;

                if (fields_read == 3) {
                    write_fmt_phone(fields);
                    fields_read = 0;
                    mark = 3;
                }
            } 
        }
    }
}

int to_num(char buffer[]) {
    int ch, n = 0, i = 0;

    while ((ch = buffer[i++]) != '\0') {
        n += ch - '0';
        n *= 10;
    }

    return n / 10;
}

void write_fmt_phone(int fields[]) {
    printf("(%d) %d-%d\n", fields[0], fields[1], fields[2]);
}
