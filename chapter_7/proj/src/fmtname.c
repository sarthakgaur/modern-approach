#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int initial, ch;
    bool initial_read = false; // initial char read
    bool on_last = false; // reading second word

    printf("Enter a first and last name: ");

    while ((ch = getchar()) != '\n') {
        if (ch != ' ' && !initial_read) {
            initial = ch;
            initial_read = true;
        } else if (ch == ' ' && initial_read)
            on_last = true;
        else if (ch != ' ' && on_last)
            putchar(ch);
    }

    printf(", %c.\n", initial);

    return 0;
}
