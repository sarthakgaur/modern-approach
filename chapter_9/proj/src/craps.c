#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void) {
    srand((unsigned) time(NULL)); // set seed

    char ch;
    int wins = 0;
    int losses = 0;

    while (true) {
        bool won = play_game();

        if (won) {
            printf("You win!\n");
            wins++;
        } else {
            printf("You Lose!\n");
            losses++;
        }

        printf("\nPlay again? ");
        ch = getchar();
        if (ch != 'Y' && ch != 'y')
            break;

        // clean the entire input line
        while(getchar() != '\n')
            ;

        printf("\n");
    }

    printf("Wins: %d  Losses: %d\n", wins, losses);

    return 0;
}

int roll_dice(void) {
    int r1 = 1 + rand() % 6;
    int r2 = 1 + rand() % 6;

    return r1 + r2;
}

bool play_game(void) {
    bool first_roll = true;
    int point = 0;

    while (true) {
        int r = roll_dice();
        printf("You rolled: %d\n", r);

        if (first_roll) {
            if (r == 7 || r == 11) return true;
            else if (r == 2 || r == 3 || r == 12) return false;

            first_roll = false;
            point = r;
            printf("You point is %d\n", point);
        }
        
        else if (r == point) return true;
        else if (r == 7) return false;
    }
}
