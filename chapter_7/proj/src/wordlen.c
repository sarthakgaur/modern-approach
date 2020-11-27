#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int chars, words;
    int ch;

    printf("Enter a sentence: ");

    bool last_alpha = false;

    while ((ch = getchar()) != '\n') {
        if (ch == ' ' && last_alpha) {
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
    
    float average_len = (float) chars / words;

    printf("Average word length: %.1f\n", average_len);

    return 0;
}
