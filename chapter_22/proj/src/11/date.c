#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DATE_LEN 10

int main(void) {
    char date_format[DATE_LEN + 1];
    bool valid_fmt = false;
    int m, d, y;

    printf("Enter a date (mm-dd-yyyy / mm/dd/yyyy): ");
    fgets(date_format, sizeof(date_format), stdin);

    if (sscanf(date_format, "%d-%d-%d", &m, &d, &y) == 3)
        valid_fmt = true;
    else if (sscanf(date_format, "%d/%d/%d", &m, &d, &y) == 3)
        valid_fmt = true;

    if (!valid_fmt) {
        fprintf(stderr, "Error: date not in correct format\n");
        exit(EXIT_FAILURE);
    }

    char *months[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    };

    printf("%s %d, %d\n", months[m-1], d, y);

    return 0;
}
