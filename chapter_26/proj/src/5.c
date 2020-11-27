#include <stdio.h>
#include <time.h>

int main(void) {
    int m, d, y;
    struct tm t;
    struct tm t2;
    time_t tt1;
    time_t tt2;

    printf("Enter a date1 (mm/dd/yy): ");
    scanf("%d/%d/%d", &m, &d, &y);

    t.tm_sec = 0;
    t.tm_min = 0;
    t.tm_hour = 0;
    t.tm_mday = d;
    t.tm_mon = m;
    t.tm_year = y - 1900;
    t.tm_isdst = -1;

    tt1 = mktime(&t);

    printf("Enter a date2 (mm/dd/yy): ");
    scanf("%d/%d/%d", &m, &d, &y);

    t2.tm_sec = 0;
    t2.tm_min = 0;
    t2.tm_hour = 0;
    t2.tm_mday = d;
    t2.tm_mon = m;
    t2.tm_year = y - 1900;
    t2.tm_isdst = -1;

    tt2 = mktime(&t2);

    double time_diff = (difftime(tt2, tt1) / 3600) / 24;

    printf("Time difference (in days): %f\n", time_diff);

    return 0;
}

