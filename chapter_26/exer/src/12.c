#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t first_day(int year);

int main(void) {
    time_t tt = first_day(2011);
    printf("%s\n", ctime(&tt));
    return 0;
}

time_t first_day(int year) {
    struct tm t;

    t.tm_sec = 0;
    t.tm_min = 0;
    t.tm_hour = 0;
    t.tm_mday = 1;
    t.tm_mon = 0;
    t.tm_year = year - 1900;
    t.tm_isdst = -1;

    return mktime(&t);
}
