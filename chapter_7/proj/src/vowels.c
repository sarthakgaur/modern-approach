#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch;
    int vcount = 0; // don't forget to intialize your counters

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);

        switch (ch) {
            case 'A': 
            case 'E': 
            case 'I': 
            case 'O': 
            case 'U': vcount++;
                      break; 
        }
    }

    printf("Your sentence contains %d vowels.\n", vcount);

    return 0;
}
