#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HOURS 24
#define DAYS 30

int main(void) {
    int temps[DAYS][HOURS];
    float agg_temp_day = 0;

    srand((unsigned) time(NULL)); // seed

    for (int i = 0; i < DAYS; i++) {
        int total_day = 0;

        for (int j = 0; j < HOURS; j++) {
            int rand_temp = 30 + rand() % 10;
            temps[i][j] = rand_temp;
            total_day += rand_temp;
            printf("%d ", rand_temp);
        }

        float avg_daily = ((float) total_day) / HOURS;
        agg_temp_day += avg_daily;
        printf("\n");
    }

    printf("\nAverage monthly temperature: %f\n", agg_temp_day / DAYS);

    return 0;
}
