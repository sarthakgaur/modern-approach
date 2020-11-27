#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 26

void read_word(int counts[SIZE]);
bool equal_array(int counts1[SIZE], int counts2[SIZE]);

int main(void) {
    int counts1[SIZE] = {0};
    int counts2[SIZE] = {0};

    printf("Enter first word: ");
    read_word(counts1);

    printf("Enter second word: ");
    read_word(counts2);

    bool are_same = equal_array(counts1, counts2);

    if (are_same)
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");


    return 0;
}

void read_word(int counts[SIZE]) {
    char ch;
    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);
        if (ch >= 'A' && ch <= 'Z')
            counts[ch - 'A']++;
    }
}

bool equal_array(int counts1[SIZE], int counts2[SIZE]) {
    for (int i = 0; i < SIZE; i++)
        if (counts1[i] != counts2[i])
            return false;

    return true;
}
