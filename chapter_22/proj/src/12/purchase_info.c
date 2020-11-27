#include <stdio.h>
#include <stdlib.h>

#define LINE_LEN 100

void print_fmt_data(FILE *fp);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: purchase_info filename\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "Error: %s could not be opened\n");
        exit(EXIT_FAILURE);
    }

    print_fmt_data(fp);

    fclose(fp);

    return 0;
}

void print_fmt_data(FILE *fp) {
    char line_buffer[LINE_LEN + 1];
    int item, m, d, y;
    float price;

    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");

    while (fgets(line_buffer, LINE_LEN, fp) != NULL) {
        sscanf(line_buffer, "%d,%f,%d/%d/%d", &item, &price, &m, &d, &y);
        printf("%d\t\t$ %6.2f\t%d/%d/%d\n", item, price, m, d, y);
    }
}
