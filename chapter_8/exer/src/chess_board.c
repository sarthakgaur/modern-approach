#include <stdio.h>

#define SIZE 8

int main(void) {
    char chess_board[SIZE][SIZE] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}, 
                                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'}, 
                                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '}, 
                                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'}, 
                                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '}, 
                                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, 
                                    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", chess_board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
