#include <stdio.h>
#include <stdbool.h>

void split_date(int day_of_year, int year, int *month, int *day);

int main(void) {
    int month, day;

    split_date(135, 2020, &month, &day);

    printf("month: %d, day: %d\n", month, day);

    return 0;
}

void split_date(int day_of_year, int year, int *month, int *day) {
    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int month_count;
    bool leap_year = false;

    if (year % 4 == 0 && year % 400 && year % 100 != 0)
        leap_year = true;

    month_days[1] = leap_year ? 29 : 28;

    for (month_count = 0; month_count < 12; month_count++) {
        if (day_of_year - month_days[month_count] >= 0)
            day_of_year -= month_days[month_count];
        else
            break;
    }

    *month = month_count + 1;
    *day = day_of_year;
}
