/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 /* maximum number of reminders */
#define MSG_LEN 60 /* max length of reminder message */

int read_line(char str[], int n);

int main(void) {
    char reminders[MAX_REMIND][MSG_LEN+3];
    char time_str[6], msg_str[MSG_LEN+1];
    int times[MAX_REMIND];
    int day, month, ctime, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter month/day and reminder: ");
        scanf("%2d/%2d", &month, &day);
        if (month == 0 || day == 0)
            break;
        sprintf(time_str, "%2d/%2d", month, day);
        read_line(msg_str, MSG_LEN);

        ctime = month * 31 + day;

        for (i = 0; i < num_remind; i++)
            if (ctime < times[i])
                break;
        for (j = num_remind; j > i; j--) {
            strcpy(reminders[j], reminders[j-1]);
            times[j] = times[j-1];
        }

        strcpy(reminders[i], time_str);
        strcat(reminders[i], msg_str);

        times[i] = ctime;

        num_remind++;
    }

    printf("\n  Time Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);

    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
