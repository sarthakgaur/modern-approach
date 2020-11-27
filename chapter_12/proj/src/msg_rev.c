#include <stdio.h>

#define SIZE 100

void rev1(int a[], int n);
void rev2(int a[], int n);

int main(void) {
    int buffer[SIZE], *p, len = 0, ch;
    printf("Enter a message: ");

    p = buffer;
    while ((ch = getchar()) != '\n' && len < SIZE) {
        *p++ = ch;
        len++;
    }

    rev1(buffer, len);
    rev2(buffer, len);

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
