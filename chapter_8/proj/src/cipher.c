#include <stdio.h>
#include <ctype.h>

#define SIZE 80

int main(void) {
    char buffer[SIZE];
    char ch;
    int sen_len = 0;

    printf("Enter a message to be encrypted: ");

    while ((ch = getchar()) != '\n') {
        buffer[sen_len] = ch;
        sen_len++;
    }

    int shift;
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    printf("Encrypted message: ");
    // shift the characters
    for (int i = 0; i < sen_len; i++) {
        ch = buffer[i];
        char upper_ch = toupper(ch);

        if (upper_ch >= 'A' && upper_ch <= 'Z') {
            if (ch == upper_ch)
                ch = (ch - 'A' + shift) % 26 + 'A';
            else
                ch = (ch - 'a' + shift) % 26 + 'a';
        }

        putchar(ch); // print the char 
    }

    putchar('\n');

    return 0;
}
