#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void to_title_case();

int main(void) {
    to_title_case();
    return 0;
}

void to_title_case() {
    int ch;
    bool in_word = false;

    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            if (!in_word) {
                ch = toupper(ch);
                in_word = true;
            } 
        } else if (ch == ' ' || ch == '\n' || ch == '\t') {
            in_word = false;
        }

        putchar(ch);
    }
}
