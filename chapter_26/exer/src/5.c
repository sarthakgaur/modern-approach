#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char *vstrcat(const char *first, ...);

int main(void) {
    char *full_str;

    full_str = vstrcat("first", "second", "third", "fourth", "fifth", NULL);
    printf("%s\n", full_str);

    free(full_str);
    return 0;
}

char *vstrcat(const char *first, ...) {
    va_list al;
    int len = 0;
    char *str, *full_str;

    va_start(al, first);
    len += strlen(first);
    while ((str = va_arg(al, char *)) != NULL)
        len += strlen(str);

    // forgot the va_end here
    full_str = malloc(len + 1);
    if (full_str == NULL) {
        va_end(al);
        return NULL;
    }

    va_start(al, first);
    strcpy(full_str, first);
    while ((str = va_arg(al, char *)) != NULL)
        strcat(full_str, str);

    va_end(al);
    return full_str;
}

