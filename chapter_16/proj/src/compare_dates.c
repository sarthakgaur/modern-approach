#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

int main(void) {
    struct date d1, d2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

    if (d1.year < d2.year)
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
    else if (d1.year > d2.year)
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d\n", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
    else if (d1.month < d2.month)
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
    else if (d1.month > d2.month)
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d\n", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
    else if (d1.day < d2.day)
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
    else if (d1.day > d2.day)
        printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d\n", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);
    else
        printf("Dates are same.\n");

    return 0;
}
