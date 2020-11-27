/* I hate maintaining this file */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LINE_LEN 100
#define INIT_SCH_SIZE 10

struct arrival_departure {
    int departure;
    int arrival;
};

void print_result_time(int rd, int ra);
int get_schedule(FILE *fp, struct arrival_departure **schedule);
void terminate(const char *msg);

int main(void) {
    FILE *fp = fopen("flights.dat", "r");

    if (fp == NULL)
        terminate("could not open flights.dat file\n");

    struct arrival_departure *schedule;
    int len;

    len = get_schedule(fp, &schedule);

    int h, m; // hour and minutes entered by the user
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &h, &m);

    int user_t = h * 60 + m; // user time after midnight

    int rd, ra;
    int td1, td2; // temprary departure times
    int old_dep, new_dep, old_arr, new_arr;

    for (int i = 0; i < len; i++) {
        new_dep = schedule[i].departure;
        new_arr = schedule[i].arrival;

        if (i != 0) {
            old_dep = schedule[i-1].departure;
            old_arr = schedule[i-1].arrival;
        }

        if (user_t < new_dep) {
            if (i == 0) {
                rd = new_dep;
                ra = new_arr;
                break;
            }

            td1 = user_t - old_dep;
            td2 = new_dep - user_t;

            rd = td1 < td2 ? old_dep : new_dep;
            ra = td1 < td2 ? old_arr : new_arr;
            break;
        }
    }

    print_result_time(rd, ra);

    fclose(fp);
    free(schedule);

    return 0;
}

void print_result_time(int rd, int ra) {
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
}

int get_schedule(FILE *fp, struct arrival_departure **schedule) {
    char line_buffer[LINE_LEN];
    int current_size = INIT_SCH_SIZE;
    int current_slot = 0;
    int dh, dm, ah, am;

    *schedule = malloc(current_size * sizeof(struct arrival_departure));

    if (schedule == NULL)
        terminate("Error: malloc failed in get_schedule\n");

    while (fgets(line_buffer, sizeof(line_buffer), fp) != NULL) {
        if (sscanf(line_buffer, "%d:%d %d:%d", &dh, &dm, &ah, &am) == 4) {
            (*schedule)[current_slot].departure = dh * 60 + dm;
            (*schedule)[current_slot].arrival = ah * 60 + am;
        } else
            terminate("Error: flights.dat is not in valid format\n");

        current_slot++;

        // forgot realloc failure check
        if (current_slot == current_size) {
            current_size *= 2;
            *schedule = realloc(schedule, current_size * sizeof(struct arrival_departure));
            if (*schedule == NULL)
                terminate("Error: realloc failed in get_schedule\n");
        }
    }

    if (current_slot == 0)
        terminate("Error: flights.dat is empty\n");

    return current_slot;
}

void terminate(const char *msg) {
    fprintf(stderr, msg);
    exit(EXIT_FAILURE);
}
