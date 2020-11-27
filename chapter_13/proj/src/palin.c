#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 100

bool check_palin(char buffer[], int n);
bool check_palin2(char buffer[], int n);
bool is_palindrome(const char *message);

int main(void) {
    char buffer[SIZE+1];
    char ch, len = 0;
    char *p = buffer;

    printf("Enter a message: ");

    while ((ch = getchar()) != '\n' && len < SIZE) {
        ch = toupper(ch);
        if (ch < 'A' || ch > 'Z') continue;

        *p++ = ch;
        len++;
    }
    *p = '\0';

    bool res1 = check_palin(buffer, len);
    bool res2 = check_palin2(buffer, len);
    bool res3 = is_palindrome(buffer);

    if (res1) printf("res1: Palindrome\n");
    else printf("res1: Not a palindrome\n");

    if (res2) printf("res2: Palindrome\n");
    else printf("res2: Not a palindrome\n");

    if (res3) printf("res3: Palindrome\n");
    else printf("res3: Not a palindrome\n");

    return 0;
}

bool check_palin(char buffer[], int n) {
    int i = 0;
    int ri = n - 1;

    while (i <= ri) {
        if (buffer[i] != buffer[ri])
            return false;
        i++;
        ri--;
    }

    return true;
}

bool check_palin2(char buffer[], int n) {
    char *p = buffer;
    char *rp = buffer + n - 1;

    while (p <= rp) {
        if (*p != *rp)
            return false;
        p++;
        rp--;
    }

    return true;
}

bool is_palindrome(const char *message) {
    const char *last = message;

    while (*last)
        last++;
    last--;

    while (message <= last)
        if (*message++ != *last--)
            return false;

    return true;
}
