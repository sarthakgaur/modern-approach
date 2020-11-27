#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define WORD_LENGTH 20
#define MAX_WORDS 100

char *read_word(void);
int compare_words(const void *p, const void *q);

int main(void) {
    char *word;
    char **head = malloc(100 * sizeof(char *)); // should have increased the array size as it fills up.
    char **words = head;
    int count = 0;

    while (true) {
        printf("Enter word: ");
        word = read_word();

        if (word != NULL) {
            *words++ = word;
            count++;
        } else
            break;
    }

    qsort(head, count, sizeof(char *), compare_words);

    printf("\nIn sorted order: ");
    for (char **str = head; str < head + count; str++) {
        printf("%s ", *str);
    }
    printf("\n");

    return 0;
}

char *read_word(void) {
    char *word = malloc((WORD_LENGTH + 1) * sizeof(char)); // malloc failure is not checked
    char *p = word;
    char ch;
    int len = 0;

    while ((ch = getchar()) == ' ' || ch == '\t')
        ;

    while (ch != '\n' && ch != EOF) {
        if (len < WORD_LENGTH) {
            *p++ = ch;
            len++;
        }
        ch = getchar();
    }

    *p = '\0';

    if (len == 0)
        return NULL;
    return word;
}

int compare_words(const void *p, const void *q) {
    return strcmp(*(char **)p, *(char **)q);
}
