#include <stdio.h>

#define MAX_DIGITS 10
#define SEGMENTS 7

const int DG[10][7] = {{1, 1, 0, 1, 1, 1, 1},  // 0
                       {0, 0, 0, 1, 0, 0, 1},  // 1
                       {1, 0, 1, 1, 1, 1, 0},  // 2
                       {1, 0, 1, 1, 0, 1, 1},  // 3
                       {0, 1, 1, 1, 0, 0, 1},  // 4
                       {1, 1, 1, 0, 0, 1, 1},  // 5
                       {1, 1, 1, 0, 1, 1, 1},  // 6
                       {1, 0, 0, 1, 0, 0, 1},  // 7
                       {1, 1, 1, 1, 1, 1, 1},  // 8
                       {1, 1, 1, 1, 0, 1, 1}}; // 9

void print_digits(int digits[], int len);

int main(void) {
    int digits[MAX_DIGITS], len = 0;
    char ch;

    printf("Enter a number: ");
    while ((ch = getchar()) != '\n' && len < MAX_DIGITS) {
        if (ch >= '0' && ch <= '9') {
            digits[len] = ch - '0';
            len++;
        }
    }

    print_digits(digits, len);

    return 0;
}

void print_digits(int digits[], int len) {
    char ch1, ch2, ch3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < len; j++) {
            int d = digits[j];

            if (i == 0) {
                ch2 = DG[d][0] == 1 ? '_' : ' ';
                ch1 = ch3 = ' ';
            } else {
                int t = i == 1 ? 0 : 3;
                ch1 = DG[d][t+1] == 1 ? '|' : ' ';
                ch2 = DG[d][t+2] == 1 ? '_' : ' ';
                ch3 = DG[d][t+3] == 1 ? '|' : ' ';
            }
            printf("%c%c%c ", ch1, ch2, ch3);
        }
        printf("\n");
    }
}
