#include <stdio.h>

#define SIZE 8

// Missed the empty type
typedef enum {
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING,
} Piece;

typedef enum {
    BLACK,
    WHITE,
} Color;

typedef struct {
    Piece piece;
    Color color;
} Square;

int main(void) {
    Square board[SIZE][SIZE] = {
        {{ROOK, BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {QUEEN, BLACK}, {KING, BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK, BLACK}},
        {{PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}},
        {{.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}},
        {{.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}},
        {{.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}},
        {{.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}, {.color=BLACK}},
        {{PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}},
        {{ROOK, WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {QUEEN, WHITE}, {KING, BLACK}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK, WHITE}},
    }; 

    return 0;
}
