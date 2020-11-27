#include <stdio.h>
#include <string.h>

#define SIZE 100

void capitalize_all_gs(char *s);

int main(void) {
    char str[SIZE];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    capitalize_all_gs(str);
    printf("res: %s\n", str);

    return 0;
}

void capitalize_all_gs(char *s) {
    s = strrchr(s, 'g');
    while (s != NULL) {
        *s = 'G';
        s = strrchr(s + 1, 'g');
    }
    return;
}
