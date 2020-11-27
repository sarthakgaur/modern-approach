#include <stdio.h>
#include <stdbool.h>

#define SIZE 200

double compute_average_word_length(const char *sentence);

int main(void) {
    char *p, ch, sentence[SIZE+1];
    double avg_len;
    p = sentence; // don't forget to initialize your pointers

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n' && p < sentence + SIZE)
        *p++ = ch;
    *p = '\0'; // don't forget the terminating character

    avg_len = compute_average_word_length(sentence);

    printf("Average word length: %.1f\n", avg_len);

    return 0;
}

double compute_average_word_length(const char *sentence) {
    int chars, words;
    const char *p;
    bool last_alpha = false;

    chars = words = 0;
    p = sentence;

    while (*p) {
        if (*p++ == ' ' && last_alpha) {
            words++;
            last_alpha = false;
        } else {
            last_alpha = true;
            chars++;
        }
    }

    if (last_alpha)
        words++;

    // for debugging
    // printf("chars: %d\n", chars);
    // printf("words: %d\n", words);
    
    return (double) chars / words;
}
