#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 26

int main(void) {
    char freq[26] = {0};
    char ch;

    printf("Enter first word: ");
    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);

        if (ch >= 'A' && ch <= 'Z')
            freq[ch - 'A']++;
    }

    printf("Enter second word: ");
    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);

        if (ch >= 'A' && ch <= 'Z')
            freq[ch - 'A']--;
    }

    bool all_zero = true;

    for (int i = 0; i < SIZE; i++) {
        if (freq[i] > 0) {
            all_zero = false;
            break;
        }
    }

    if (all_zero)
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");


    return 0;
}
