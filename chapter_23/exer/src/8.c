#include <stdio.h>
#include <string.h>

#define SIZE 100

int numchar(const char *s, char ch);

int main(void) {
    char str[SIZE+1], ch;
    int count;

    printf("Enter a string: ");
    fgets(str, SIZE, stdin);

    printf("Enter a char: ");
    scanf("%c", &ch);

    count = numchar(str, ch);

    printf("Number of repeated ch: %d\n", count);

    return 0;
}

int numchar(const char *s, char ch) {
    int count = 0;
    const char *p = s - 1;

    while ((p = strchr(p + 1, ch)) != NULL)
        count++;

    return count;
}
