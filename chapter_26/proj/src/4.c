#include <stdio.h>
#include <time.h>

int main(void) {
    int m, d, y, n;
    struct tm t;

    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m, &d, &y);

    printf("Enter days to add: ");
    scanf("%d", &n);

    t.tm_sec = 0;
    t.tm_min = 0;
    t.tm_hour = 0;
    t.tm_mday = d;
    t.tm_mon = m;
    t.tm_year = y - 1900;
    t.tm_isdst = -1;

    t.tm_mday += n;

    mktime(&t);

    printf("Date after addition: %s\n", asctime(&t));

    return 0;
}

