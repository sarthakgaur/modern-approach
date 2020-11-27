#include <stdio.h>

int main(void) {
    int days, start;

    printf("Enter number of days in month: ");
    scanf("%d", &days);

    printf("Enter starting day of the week: ");
    scanf("%d", &start);

    for (int i = 1; i < start; i++)
        printf("   "); // 3 spaces

    int weekday = start;

    for (int i = 1; i <= days; i++) {
        printf("%2d ", i);
        if (weekday == 7) {
            printf("\n");
            weekday = 1;
        } else {
            weekday++;
        }
    }

    printf("\n");

    return 0;
}
