#include <stdio.h>
#include <string.h>

#define SIZE 100

void rev1(int a[], int n);
void rev2(int a[], int n);
void reverse(char *message);

int main(void) {
    char buffer[SIZE+1], *p, len = 0, ch;
    printf("Enter a message: ");

    p = buffer;
    while ((ch = getchar()) != '\n' && len < SIZE) {
        *p++ = ch;
        len++;
    }
    *p = '\0';

    reverse(buffer);
    // rev1(buffer, len);
    // rev2(buffer, len);

    printf("%s\n", buffer);

    return 0;
}

void rev1(int a[], int n) {
    for (int i = n - 1; i >= 0; i--)
        putchar(a[i]);
    putchar('\n');
}

void rev2(int a[], int n) {
    for (int *p = a + n - 1; p >= a; p--)
        putchar(*p);
    putchar('\n');
}

void reverse(char *message) {
    char *last = message;
    char tmp;

    while (*last)
        last++;
    last--;


    while (message < last) {
        tmp = *message;
        *message = *last;
        *last = tmp;
        message++, last--;
    }
}
