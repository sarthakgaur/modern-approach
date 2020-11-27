#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 30

bool are_anagrams(const char *word1, const char *word2);

int main(void) {
    char word1[SIZE+1];
    char word2[SIZE+1];
    char ch;
    int i;

    printf("Enter first word: ");
    i = 0;
    while ((ch = getchar()) != '\n' && i < SIZE) {
        ch = toupper(ch);
        if (ch >= 'A' && ch <= 'Z')
            word1[i++] = ch;
    }
    word1[i] = '\0';


    printf("Enter second word: ");
    i = 0;
    while ((ch = getchar()) != '\n' && i < SIZE) {
        ch = toupper(ch);
        if (ch >= 'A' && ch <= 'Z')
            word2[i++] = ch;
    }
    word1[i] = '\0';

    bool anagrams = are_anagrams(word1, word2);

    if (anagrams)
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");


    return 0;
}

bool are_anagrams(const char *word1, const char *word2) {
    char freq[26] = {0};

    while (*word1)
        freq[*word1++ - 'A']++;

    while (*word2)
        freq[*word2++ - 'A']--;

    for (int i = 0; i < 26; i++)
        if (freq[i] != 0)
            return false;

    return true;
}
