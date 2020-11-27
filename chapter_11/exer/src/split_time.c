#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main(void) {
    int hr, min, sec;

    split_time(84858, &hr, &min, &sec);

    printf("h: %d, m: %d, s: %d\n", hr, min, sec);

    return 0;
}

void split_time(long total_sec, int *hr, int *min, int *sec) {
    *sec = total_sec % 60;
    total_sec -= *sec;

    *min = total_sec / 60 % 60;
    total_sec -= *min;

    *hr = total_sec / 60 / 60;
}
