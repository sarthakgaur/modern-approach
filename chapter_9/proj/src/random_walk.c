#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void generate_random_walk(char grid[][10]);
void print_array(char grid[][10]);

int main(void) {
    char grid[SIZE][SIZE];

    generate_random_walk(grid);
    print_array(grid);

    return 0;
}

void generate_random_walk(char grid[][10]) {
    // set complete grid to '.'
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            grid[i][j] = '.';

    srand((unsigned) time(NULL)); // setting the seed

    // setting x and y coordinates and setting the starting character
    char letter = 'A';
    int x = 0;
    int y = 0;

    // if all directions are blocked, this will be false
    bool step_possible = true;

    while (letter <= 'Z' && step_possible) {
        grid[x][y] = letter;

        // old positions of x and y
        int ox = x;
        int oy = y;

        bool processing_step = true;

        // initially all sides are valid
        int valid_steps[] = {true, true, true, true};
        int side_blocked = 0;

        while (processing_step) {
            int next_step = rand() % 4;

            // if all sides are blocked, exit both loops
            if (side_blocked == 4) {
                step_possible = false;
                break;
            }

            // continue if current step is invalid, but valid step is possible
            if (!valid_steps[next_step]) {
                continue;
            }

            switch (next_step) {
                case 0: x--; // go up
                        break;
                case 1: y++; // go right 
                        break;
                case 2: x++; // go down
                        break;
                case 3: y--; // go left
                        break;
            }

            // check the array bounds and previous steps
            if (x < SIZE && x >= 0
                    && y < SIZE && y >= 0
                    && grid[x][y] == '.') {
                letter++;
                processing_step = false;
            } else {
                valid_steps[next_step] = false;
                side_blocked++;
                x = ox, y = oy; // reset x and y
            }
        }
    }
}

void print_array(char grid[][10]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}
