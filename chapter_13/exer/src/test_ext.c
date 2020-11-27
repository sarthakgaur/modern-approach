#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool test_extension(const char *file_name, const char *extension);

int main(void) {
    printf("1: %d\n", test_extension("hello.txt", "TXT"));
    printf("2: %d\n", test_extension("hello.java", "javs"));
    printf("3: %d\n", test_extension("hello.java", "java"));
    return 0;
}

bool test_extension(const char *file_name, const char *extension) {
    char fext, ext;
    bool has_ext = false;

    while (*file_name != '\0')
        if (*file_name++ == '.') {
            has_ext = true;
            break;
        }

    if (!has_ext) return false;
    if (strlen(file_name) != strlen(extension)) return false;

    while (*file_name != '\0') {
        fext = toupper(*file_name);
        ext = toupper(*extension);
        if (fext != ext)
            return false;
        file_name++, extension++;
    }

    return true;
}
