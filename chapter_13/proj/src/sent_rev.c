#include <stdio.h>
#include <stdbool.h>

#define ROW 30
#define COL 20

int fill_word_arr(char buffer[][COL+1], char *last_chr, int row, int col);
void print_rev(char buffer[][COL+1], char last_chr, int nrow, int col);

int main(void) {
    char buffer[ROW][COL+1];
    char last_chr;
    int nrow;

    printf("Enter a sentence: ");
    nrow = fill_word_arr(buffer, &last_chr, ROW, COL);
    print_rev(buffer, last_chr, nrow, COL);

    return 0;
}

int fill_word_arr(char buffer[][COL+1], char *last_chr, int row, int col) {
    char ch;
    int i, j;
    i = j = 0;

    bool in_wrd = false;

    while ((ch = getchar()) != '.' && ch != '!' && ch != '?') {
        if (ch != ' ' && j < col) { // check col size
            buffer[i][j++] = ch;
            in_wrd = true;
        } else if (in_wrd) {
            if (i >= row) break; // check row size
            in_wrd = false;
            buffer[i][j] = '\0';
            i++, j = 0;
        }
    }

    buffer[i][j] = '\0'; // terminating char for last word.
    *last_chr = ch;

    return i;
}

void print_rev(char buffer[][COL+1], char last_chr, int nrow, int col) {
    int i, j;
    i = nrow;
    j = 0;

    while (i >= 0) {
        while (buffer[i][j])
           putchar(buffer[i][j++]);
        if (i > 0) putchar(' ');
        i--, j = 0;
    }

    putchar(last_chr);
    putchar('\n');
}
