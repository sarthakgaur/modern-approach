/* Prints a one-month reminder list (dynamic string version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50 /* maximum number of reminders */
#define MSG_LEN 60 /* max length of reminder message */

struct vstring {
    int len;
    char chars[]; // struct hack
};

int read_line(char str[], int n);
void *malloc_wrapper(int bytes);
void write_vstring(struct vstring *vstring_pt, char *str, int size);

int main(void) {
    struct vstring **reminders = malloc_wrapper(MAX_REMIND * sizeof(struct vstring *));
    char day_str[3], msg_str[MSG_LEN];
    int day, i, j, num_remind = 0;
    int msg_size;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);
        msg_size = read_line(msg_str, MSG_LEN) + 2; // 2 for day str

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]->chars) < 0)
                break;
        for (j = num_remind; j > i; j--)
            reminders[j] = reminders[j-1];

        reminders[i] = malloc_wrapper(sizeof(struct vstring) + msg_size);
        reminders[i]->len = 0;

        write_vstring(reminders[i], day_str, msg_size);
        write_vstring(reminders[i], msg_str, msg_size);

        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++) {
        for (j = 0; j < reminders[i]->len; j++)
            printf("%c", reminders[i]->chars[j]); // forgot that there is no null character.
        printf("\n");
    }

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

void *malloc_wrapper(int bytes) {
    void *temp = malloc(bytes);
    if (temp == NULL) {
        printf("Error: malloc failed in malloc_wrapper\n");
        exit(EXIT_FAILURE);
    }

    return temp;
}

void write_vstring(struct vstring *vstring_pt, char *str, int size) {
    char *vch = vstring_pt->chars + vstring_pt->len;

    while (*str != '\0' && vch < vch + size) {
        *vch++ = *str++;
        vstring_pt->len++;
    }
}
