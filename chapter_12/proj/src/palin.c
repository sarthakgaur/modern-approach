#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define SIZE 100

bool check_palin(int buffer[], int n);
bool check_palin2(int buffer[], int n);

int main(void) {
    int buffer[SIZE], ch, len = 0;
    int *p = buffer;

    printf("Enter a message: ");

    while ((ch = getchar()) != '\n' && len < SIZE) {
        ch = toupper(ch);
        if (ch < 'A' || ch > 'Z') continue;

        *p++ = ch;
        len++;
    }

    bool res1 = check_palin(buffer, len);
    bool res2 = check_palin2(buffer, len);

    if (res1) printf("res1: Palindrome\n");
    else printf("res1: Not a palindrome\n");

    if (res2) printf("res2: Palindrome\n");
    else printf("res2: Not a palindrome\n");

    return 0;
}

bool check_palin(int buffer[], int n) {
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

bool check_palin2(int buffer[], int n) {
    int *p = buffer;
    int *rp = buffer + n - 1;

    while (p <= rp) {
        if (*p != *rp)
            return false;
        p++;
        rp--;
    }

    return true;
}
