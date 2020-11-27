#include <stdio.h>
#include <time.h>

#define SIZE 100

int main(void) {
    char date_buffer[SIZE];
    char am_or_pm = 'a';
    struct tm t;

    t.tm_sec = 34;
    t.tm_min = 48;
    t.tm_hour = 17;
    t.tm_mday = 3;
    t.tm_mon = 5;
    t.tm_year = 107;
    t.tm_isdst = -1;

    mktime(&t);

    if (t.tm_hour > 12)
        am_or_pm = 'p';

    strftime(date_buffer, sizeof(date_buffer), "%A, %B %d, %Y %I:%M", &t);
    printf("%s%c\n", date_buffer, am_or_pm);

    strftime(date_buffer, sizeof(date_buffer), "%a, %d %b %y  %H:%M", &t);
    printf("%s\n", date_buffer);

    strftime(date_buffer, sizeof(date_buffer), "%D  %I:%M:%S %p", &t);
    printf("%s\n", date_buffer);

    return 0;
}
