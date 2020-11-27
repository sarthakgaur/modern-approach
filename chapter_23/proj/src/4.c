#include <stdio.h>
#include <string.h>

#define SIZE 200

void reverse_words(char *str);

int main(void) {
    char buffer[SIZE];

    printf("Enter a series of words: ");
    fgets(buffer, sizeof(buffer), stdin);

    reverse_words(buffer);

    return 0;
}

void reverse_words(char *str) {
    char *stack_token_ptr[SIZE];
    char *deli = " \n";
    int last, i = 0;

    str = strtok(str, deli);

    if (str == NULL)
        return;

    do {
        if (i == SIZE)
            break;

        stack_token_ptr[i++] = str;
    } while ((str = strtok(NULL, deli)) != NULL);

    last = i - 1;

    while (last >= 0) {
        printf(last > 0 ? "%s " : "%s", stack_token_ptr[last]);
        last--;
    }

    putchar('\n');
}

