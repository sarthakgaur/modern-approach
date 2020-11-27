#include <stdio.h>
#include <stdbool.h>

#define SIZE 20

int main(void) {
    int initial, ch;
    bool initial_read = false; // initial char read
    bool on_last = false; // reading second word
    char lastname[SIZE];

    printf("Enter a first and last name: ");

    int len = 0;
    while ((ch = getchar()) != '\n') {
        if (ch != ' ' && !initial_read) {
            initial = ch;
            initial_read = true;
        } else if (ch == ' ' && initial_read)
            on_last = true;
        else if (ch != ' ' && on_last && len < 20) {
            lastname[len] = ch;
            len++;
        }
    }

    printf("You entered the name: ");
    for (int i = 0; i < len; i++)
        printf("%c", lastname[i]);
    printf(", %c.\n", initial);

    return 0;
}
