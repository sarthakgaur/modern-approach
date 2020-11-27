#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 20

int main(void) {
    char current_word[SIZE + 1];
    char max_word[SIZE + 1] = "";
    char min_word[SIZE + 1];
    bool min_not_set = true;

    while (true) {
        printf("Enter a word: ");
        scanf("%s", current_word);

        if (min_not_set) {
            strcpy(min_word, current_word);
            min_not_set = false;
        } else if (strcmp(current_word, min_word) < 0)
            strcpy(min_word, current_word);

        if (strcmp(current_word, max_word) > 0)
            strcpy(max_word, current_word);


        if (strlen(current_word) == 4) break;
    }

    printf("\nSmallest word: %s\n", min_word);
    printf("Largest word: %s\n", max_word);

    return 0;
}
