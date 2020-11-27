#include <stdio.h>

int day_of_year(int month, int day, int year);

int main(void) {
    printf("04/07/2020: %d\n", day_of_year(4, 7, 2020));

    return 0;
}

int day_of_year(int month, int day, int year) {
    int days_in_month[] = {31, 28, 31, 30,
                           31, 30, 31, 31,
                           30, 31, 30, 31};

    // test for leap year
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        days_in_month[1] = 29;

    int total_days = 0;

    for (int i = 0; i < month - 1; i++)
        total_days += days_in_month[i];

    total_days += day;

    return total_days;
}
