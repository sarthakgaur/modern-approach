#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 50

int reverse_name(char *name);

int compute_vowel_count(const char *sentence);

int main(void) {
    char name[2*SIZE+1];

    reverse_name(name);

    printf("%s\n", name);

    return 0;
}

int reverse_name(char *name) {
    char first_name[SIZE+1];
    char last_name[SIZE+1];

    printf("Enter a first and last name: ");
    scanf("%s", first_name);
    scanf("%s", last_name);

    // capitalize the first letter of last name and first name.
    *last_name = toupper(*last_name);
    *first_name = toupper(*first_name);

    sprintf(name, "%s, %c.", last_name, *first_name);
}
