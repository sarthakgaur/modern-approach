#include <stdio.h>
#include <ctype.h>

#define SIZE 80

void encrypt(char *message, int shift);

int main(void) {
    char buffer[SIZE+1];
    char ch;
    int sen_len = 0;

    printf("Enter a message to be encrypted: ");

    while ((ch = getchar()) != '\n' && sen_len < SIZE) {
        buffer[sen_len++] = ch;
    }
    buffer[sen_len] = '\0';

    int shift;
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    encrypt(buffer, shift);

    return 0;
}

void encrypt(char *message, int shift) {
    char ch;

    printf("Encrypted message: ");

    while (*message) {
        ch = *message++;
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
}
