#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20

void *malloc_wrapper(int bytes);

struct word_node {
    char word[MAX_WORD_LEN+2];
    struct word_node *next;
};

struct word_node *first = NULL;
struct word_node **current = &first;

int line_len = 0;
int num_words = 0;

void clear_line(void) {
    struct word_node *temp;

    while (first != NULL) {
        temp = first;
        first = first->next;
        free(temp);
    }

    current = &first;

    line_len = 0;
    num_words = 0;
}

void add_word(const char *word) {
    *current = malloc_wrapper(sizeof(struct word_node));
    strcpy((*current)->word, word);
    (*current)->next = NULL;
    current = &(*current)->next;

    if (num_words > 0)
        line_len++;

    line_len += strlen(word);
    num_words++;
}

int space_remaining(void) {
    return MAX_LINE_LEN - line_len;
}

void write_line(void) {
    int extra_spaces, spaces_to_insert, i, j;
    struct word_node *entry = first;

    extra_spaces = MAX_LINE_LEN - line_len;
    while (entry != NULL) {
        printf("%s", entry->word);

        if (num_words > 1) {
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (j = 1; j <= spaces_to_insert + 1; j++)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
        }

        entry = entry->next;
        num_words--;
    }
    putchar('\n');
}

void flush_line(void) {
    struct word_node *entry = first;
    struct word_node *temp;

    while (entry != NULL) {
        temp = entry;
        printf("%s", entry->word);
        if (entry->next != NULL)
            putchar(' ');
        entry = entry->next;
        free(temp);
    }

    current = &first;
}

void *malloc_wrapper(int bytes) {
    void *temp;
    temp = malloc(bytes);

    if (temp == NULL) {
        printf("Error: malloc failed in malloc_wrapper in line.c\n");
        exit(EXIT_FAILURE);
    }

    return temp;
}
