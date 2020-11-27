#include <stdio.h>
#include <ctype.h>

#define SIZE 50

int compute_scrabble_value(const char *word);

int main(void) {
    int ch;
    int score;
    char words[SIZE];

    printf("Enter a word: ");
    scanf("%s", words);

    score = compute_scrabble_value(words);

    printf("Scrabble value: %d\n", score);

    return 0;
}

int compute_scrabble_value(const char *word) {
    const char *p = word;
    char ch;
    int score = 0;

    while (*p) {
        ch = toupper(*p);

        switch (ch) {
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U': score += 1;
                      break;
            case 'D':
            case 'G': score += 2;
                      break;
            
            case 'B':
            case 'C':
            case 'M':
            case 'P': score += 3;
                      break;

            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y': score += 4;
                      break;

            case 'K': score += 5;
                      break;

            case 'J':
            case 'X': score += 8;
                      break;

            case 'Q':
            case 'Z': score += 10;
                      break;
        }

        p++;
    }

    return score;
}
