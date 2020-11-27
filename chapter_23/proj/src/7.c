#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int count_sentences();

int main(void) {
    int res;

    res = count_sentences();
    printf("Sentences: %d\n", res);

    return 0;
}

int count_sentences() {
    int ch, ln_count = 0;
    bool term_spotted = false;

    while ((ch = getchar()) != EOF) {
        if (ch == '.' || ch == '!' || ch == '?') {
            term_spotted = true;
        } else if (term_spotted && isspace(ch)) {
            term_spotted = false;
            ln_count++;
        }
    }

    return ln_count;
}
