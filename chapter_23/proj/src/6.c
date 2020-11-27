#include <stdio.h>
#include <ctype.h>

void replace_cntrl();

int main(void) {
    replace_cntrl();
    return 0;
}

void replace_cntrl() {
    int ch;

    while ((ch = getchar()) != EOF) {
        if (ch != '\n' && iscntrl(ch))
           ch = '?';
       putchar(ch); 
    }
}
