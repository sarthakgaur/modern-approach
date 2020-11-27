#include <stdio.h>

struct schedule {
    int departure;
    int arrival;
};

int main(void) {
    // departure and arrival time after converting them to minutes after midnight
    struct schedule schedules[] = {
        {480,  616},
        {583,  712},
        {679,  811},
        {767,  900},
        {840,  968},
        {945,  1075},
        {1140, 1280},
        {1305, 1438},
    };

    int h, m; // hour and minutes entered by the user
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &h, &m);

    int user_t = h * 60 + m; // user time after midnight

    int td1, td2; // temprary departure times
    struct schedule res;
    struct schedule previous;
    struct schedule current;

    for (int i = 0; i < 8; i++) {
        if (user_t < schedules[i].departure) {
            if (i == 0) previous = schedules[7];
            else previous = schedules[i-1];

            current = schedules[i];

            td1 = user_t - previous.departure;
            td2 = current.departure - user_t;

            res = td1 < td2 ? previous : current;
            break;
        }
    }

    int dep_hour_24 = (res.departure - (res.departure % 60)) / 60;
    int dep_hour_12 = dep_hour_24 > 12 ? dep_hour_24 - 12 : dep_hour_24;
    printf("Closet departure time is %.2d:%.2d ", dep_hour_12, res.departure % 60);

    if (res.departure < 720)
        printf("a.m");
    else
        printf("p.m");

    int arr_hour_24 = (res.arrival - (res.arrival % 60)) / 60;
    int arr_hour_12 = arr_hour_24 > 12 ? arr_hour_24 - 12 : arr_hour_24;
    printf(", arriving at %.2d:%.2d ", arr_hour_12, res.arrival % 60);

    if (res.arrival < 720)
        printf("a.m");
    else
        printf("p.m");

    printf(".\n");

    return 0;
}
