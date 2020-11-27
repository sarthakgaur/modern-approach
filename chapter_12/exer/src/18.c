#include <stdio.h>
#include <ctype.h>

int evaluate_position1(char board[][8]);
int evaluate_position2(char board[][8]);

int main(void) {
    char board[8][8] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.'},
                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

    printf("starting positions1: %d\n", evaluate_position1(board));
    printf("starting positions2: %d\n", evaluate_position2(board));

    return 0;
}

int evaluate_position1(char board[][8]) {
    int white_sum = 0;
    int black_sum = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char original = board[i][j];
            char converted = toupper(original);
            int piece_val = 0;

            switch (converted) {
                case 'Q': piece_val = 9;
                          break;
                case 'R': piece_val = 5;
                          break;
                case 'B': piece_val = 3;
                          break;
                case 'N': piece_val = 3;
                          break;
                case 'P': piece_val = 1;
                          break;
            }

            if (original == converted)
                white_sum += piece_val;
            else
                black_sum += piece_val;
        }
    }

    return white_sum - black_sum;
}

int evaluate_position2(char board[][8]) {
    int white_sum = 0;
    int black_sum = 0;

    char *p;
    for (p = &board[0][0]; p < &board[8-1][8]; p++) {
            char original = *p;
            char converted = toupper(original);
            int piece_val = 0;

            switch (converted) {
                case 'Q': piece_val = 9;
                          break;
                case 'R': piece_val = 5;
                          break;
                case 'B': piece_val = 3;
                          break;
                case 'N': piece_val = 3;
                          break;
                case 'P': piece_val = 1;
                          break;
            }

            if (original == converted)
                white_sum += piece_val;
            else
                black_sum += piece_val;
    }

    return white_sum - black_sum;
}
