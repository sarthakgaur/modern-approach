#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100

void get_extension(const char *file_name, char *extension);

int main(void) {
    char file_name[SIZE], extension[SIZE], ch, *p = file_name;

    printf("Enter a file name: ");

    while ((ch = getchar()) != '\n')
        *p++ = ch;
    *p = '\0';

    get_extension(file_name, extension);

    printf("file_name: %s\n", file_name);
    printf("extension: %s\n", extension);

    return 0;
}

void get_extension(const char *file_name, char *extension) {
    bool has_ext = false;

    while (*file_name != '\0') {
        if (*file_name == '.') {
            has_ext = true;
            break;
        }
        file_name++;
    }

    if (!has_ext)
        *extension = '\0';
    else
        strcpy(extension, file_name + 1);
}
