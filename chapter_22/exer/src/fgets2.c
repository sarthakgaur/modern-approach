#include <stdio.h>

#define MAX_SIZE 100

char *fgets2(char * restrict s, int n, FILE * restrict stream);
int fputs2(const char * restrict s, FILE * restrict stream);

int main(void) {
    char str[MAX_SIZE];
    fgets2(str, sizeof(str), stdin);
    printf("%s\n", str);

    fputs2("hello\nbye\n", stdout);

    return 0;
}

char *fgets2(char * restrict s, int n, FILE * restrict stream) {
    int ch, i = 0;

    while ((ch = getc(stream)) != '\n' && ch != EOF) {
        if (ferror(stream))
            return NULL;
        if (i < n - 1)
            s[i++] = ch;
    }

    if (i == 0 && ch == EOF)
        return NULL;

    if (i + 1 < n && ch == '\n')
        s[i++] = '\n';

    s[i] = '\0';

    return s;
}

int fputs2(const char * restrict s, FILE * restrict stream) {
    int ch, i = 0;

    while ((ch = s[i]) != '\0') {
        putc(ch, stream);
        i++;

        if (ferror(stream))
            return EOF;
    }

    return i;
}
