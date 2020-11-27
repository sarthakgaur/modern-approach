#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *my_strdup(char *s);
int my_stricmp(char *s1, char *s2);
char *my_strlwr(char *s);
char *my_strrev(char *s);
char *my_strset(char *s, char ch);

int main(void) {
    char s1[] = "aPPle";
    char s2[] = "banana";

    printf("my_strdup(s1): %s\n", my_strdup(s1));
    printf("my_stricmp(s1, s2): %d\n", my_stricmp(s1, s2));
    printf("my_strlwr(s1): %s\n", my_strlwr(s1));
    printf("my_strrev(s1): %s\n", my_strrev(s1));
    printf("my_strset(s1): %s\n", my_strset(s1, 's'));

    return 0;
}

char *my_strdup(char *s) {
    int len = strlen(s);
    char *ns = malloc(len + 1);

    if (ns == NULL)
        return NULL;

    char *p = ns;

    while (*s != '\0')
        *p++ = *s++;
    *p = '\0';

    return ns;
}


int my_stricmp(char *s1, char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 < *s2)
            return -1;
        else if (*s1 > *s2)
            return 1;
        s1++;
        s2++;
    }

    if (*s1 == '\0' && *s2 == '\0')
        return 0;
    else if (*s1 == '\0')
        return -1;
    return 1;
}

char *my_strlwr(char *s) {
    char ch;
    int i = 0;

    while ((ch = s[i]) != '\0') {
        s[i] = tolower(s[i]);
        i++;
    }

    return s;
}

char *my_strrev(char *s) {
    int start = 0;
    int last = strlen(s) - 1;
    char temp;

    while (start < last) {
        temp = s[start];
        s[start] = s[last];
        s[last] = temp;
        start++;
        last--;
    }

    return s;
}

char *my_strset(char *s, char ch) {
    int len = sizeof(s);

    for (int i = 0; i < len; i++)
        s[i] = ch;
    s[len-1] = '\0';

    return s;
}
