#include <stdio.h>
#include <ctype.h>

#define SIZE 200

int compute_vowel_count(const char *sentence);

int main(void) {
    int ch, res;
    char sentence[SIZE+1]; // don't forget the terminating character

    printf("Enter a sentence: ");
    int i = 0;
    while ((ch = getchar()) != '\n' && i < SIZE)
        sentence[i++] = ch;
    sentence[i] = '\0';

    res = compute_vowel_count(sentence);

    printf("Your sentence contains %d vowels.\n", res);

    return 0;
}

int compute_vowel_count(const char *sentence) {
    const char *p = sentence;
    char ch;
    int vcount = 0;

    while (*p) {
        ch = toupper(*p);

        switch (ch) {
            case 'A': 
            case 'E': 
            case 'I': 
            case 'O': 
            case 'U': vcount++;
                      break; 
        }

        p++;
    }

    return vcount;
}
