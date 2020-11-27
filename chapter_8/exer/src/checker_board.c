#include <stdio.h>

#define SIZE 8

int main(void) {
    char ch_board[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0)
                ch_board[i][j] = 'B';
            else
                ch_board[i][j] = 'R';
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", ch_board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
