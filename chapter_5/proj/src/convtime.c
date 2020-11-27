#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int hour, minute;
    printf("Enter a 24-hour time: ");
    scanf("%d : %d", &hour, &minute);

    bool is_am = true;

    if (hour == 0) {
        hour = 12;
    } else if (hour >= 12) {
        is_am = false;
        if (hour > 12) hour -= 12;
    }

    if (is_am)
        printf("Equivalent 12-hour time: %.2d:%.2d AM\n", hour, minute);
    else
        printf("Equivalent 12-hour time: %.2d:%.2d PM\n", hour, minute);

    return 0;
}
