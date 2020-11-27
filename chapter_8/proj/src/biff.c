#include <stdio.h>
#include <ctype.h>

#define CAPACITY 500

int main(void) {
    char ch;
    char buffer[CAPACITY];

    printf("Enter message: ");

    int pos = 0;
    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);

        switch (ch) {
            case 'A': ch = '4';
                      break;
            case 'B': ch = '8';
                      break;
            case 'E': ch = '3';
                      break;
            case 'I': ch = '1';
                      break;
            case 'O': ch = '0';
                      break;
            case 'S': ch = '5';
                      break;
            default: ch = ch;
                     break;
        }

        buffer[pos] = ch;
        pos++;
    }

    printf("In B1FF-speak: ");
    for (int i = 0; i < pos; i++)
        putchar(buffer[i]);
    printf("!!!!!!!!!!\n");

    return 0;
}
