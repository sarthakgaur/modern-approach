#include <stdio.h>

void find_closet_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void) {
    int h, m; // hour and minutes entered by the user
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &h, &m);

    int user_t = h * 60 + m; // user time after midnight
    int rd, ra;

    find_closet_flight(user_t, &rd, &ra);

    int dep_hour_24 = (rd - (rd % 60)) / 60;
    int dep_hour_12 = dep_hour_24 > 12 ? dep_hour_24 - 12 : dep_hour_24;
    printf("Closet departure time is %.2d:%.2d ", dep_hour_12, rd % 60);

    if (rd < 720)
        printf("a.m");
    else
        printf("p.m");

    int arr_hour_24 = (ra - (ra % 60)) / 60;
    int arr_hour_12 = arr_hour_24 > 12 ? arr_hour_24 - 12 : arr_hour_24;
    printf(", arriving at %.2d:%.2d ", arr_hour_12, ra % 60);

    if (ra < 720)
        printf("a.m");
    else
        printf("p.m");

    printf(".\n");

    return 0;
}

void find_closet_flight(int desired_time, int *departure_time, int *arrival_time) {
    // departure and arrival time after converting them to minutes after midnight
    int d1 = 480;
    int a1 = 616;

    int d2 = 583;
    int a2 = 712;

    int d3 = 679;
    int a3 = 811;

    int d4 = 767;
    int a4 = 900;

    int d5 = 840;
    int a5 = 968;

    int d6 = 945;
    int a6 = 1075;

    int d7 = 1140;
    int a7 = 1280;

    int d8 = 1305;
    int a8 = 1438;

    int rd, ra; // result arrival and result departure
    int td1, td2; // temprary departure times

    if (desired_time < d1) {
        rd = d1;
        ra = a1;
    } else if (desired_time < d2) {
        td1 = desired_time - d1;
        td2 = d2 - desired_time;

        rd = td1 < td2 ? d1 : d2;
        ra = td1 < td2 ? a1 : a2;
    } else if (desired_time < d3) {
        td1 = desired_time - d2;
        td2 = d3 - desired_time;

        rd = td1 < td2 ? d2 : d3;
        ra = td1 < td2 ? a2 : a3;
    } else if (desired_time < d4) {
        td1 = desired_time - d3;
        td2 = d4 - desired_time;

        rd = td1 < td2 ? d3 : d4;
        ra = td1 < td2 ? a3 : a4;
    } else if (desired_time < d5) {
        td1 = desired_time - d4;
        td2 = d5 - desired_time;

        rd = td1 < td2 ? d4 : d5;
        ra = td1 < td2 ? a4 : a5;
    } else if (desired_time < d6) {
        td1 = desired_time - d5;
        td2 = d6 - desired_time;

        rd = td1 < td2 ? d5 : d6;
        ra = td1 < td2 ? a5 : a6;
    } else if (desired_time < d7) {
        td1 = desired_time - d6;
        td2 = d7 - desired_time;

        rd = td1 < td2 ? d6 : d7;
        ra = td1 < td2 ? a6 : a7;
    } else if (desired_time < d8) {
        td1 = desired_time - d7;
        td2 = d8 - desired_time;

        rd = td1 < td2 ? d7 : d8;
        ra = td1 < td2 ? a7 : a8;
    } else {
        rd = d8;
        ra = a8;
    }

    *departure_time = rd;
    *arrival_time = ra;
}
