#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define NAME_LEN 25
#define INIT_SET_SIZE 10

struct part {
    int number;
    char name[NAME_LEN];
    int on_hand;
};

int read_set(FILE *fp, struct part **set);
int merge_sets(struct part ***merge_set, struct part *set1, int len1, struct part *set2, int len2);
int comp_merge_set(const void *p, const void *q);
void write_merge(FILE *merge_fp, struct part **merge_sets, int merge_len);
void terminate(const char *msg, ...);

int main(int argc, char *argv[]) {
    if (argc != 4)
        terminate("usage: merge_records record1 record2 merge\n");

    FILE *record1_fp, *record2_fp, *merge_fp;

    record1_fp = fopen(argv[1], "rb");
    if (record1_fp == NULL)
        terminate("Error: could not open %s", argv[1]);

    record2_fp = fopen(argv[2], "rb");
    if (record1_fp == NULL) {
        fclose(record1_fp);
        terminate("Error: could not open %s", argv[2]);
    }

    merge_fp = fopen(argv[3], "wb");
    if (record1_fp == NULL) {
        fclose(record1_fp);
        fclose(record2_fp);
        terminate("Error: could not open %s", argv[3]);
    }

    struct part *set1, *set2;
    struct part **merge_set;
    int len1, len2, merge_len;

    // Initialize all pointers
    set1 = set2 = NULL; 
    merge_set = NULL;

    len1 = read_set(record1_fp, &set1);
    len2 = read_set(record2_fp, &set2);
    merge_len = merge_sets(&merge_set, set1, len1, set2, len2);
    qsort(merge_set, merge_len, sizeof(struct part *), comp_merge_set);
    write_merge(merge_fp, merge_set, merge_len);

    // free resources
    fclose(record1_fp);
    fclose(record2_fp);
    fclose(merge_fp);
    free(set1);
    free(set2);

    return 0;
}

int read_set(FILE *fp, struct part **set) {
    int current_size, count = 0;

    *set = malloc(INIT_SET_SIZE * sizeof(struct part));
    if (*set == NULL)
        terminate("Error: malloc failed in read_set\n");

    current_size = INIT_SET_SIZE;

    while (fread(&((*set)[count]), sizeof(struct part), 1, fp) == 1) {
        count++;

        if (count == current_size) {
            current_size *= 2;

            *set = realloc(*set, current_size * sizeof(struct part));
            if (set == NULL)
                terminate("Error: realloc failed in read_set\n");
        }
    }

    return count;
}

int merge_sets(struct part ***merge_set, struct part *set1, int len1, struct part *set2, int len2) {
    *merge_set = malloc((len1 + len2) * sizeof(struct part *));
    if (*merge_set == NULL)
        terminate("Error: malloc failed in merge_sets\n");

    int len = 0;
    int copies[len2];

    for (int i = 0; i < len2; i++)
        copies[i] = 0;

    for (int i = 0; i < len1; i++) {
        (*merge_set)[len++] = &set1[i];

        for (int j = 0; j < len2; j++) {
            if (set1[i].number == set2[j].number) {
                // check corruption
                if (set1[i].name != set2[j].name)
                    terminate("Error: parts %s and %s have different names but same number %d\n",
                            set1[i].name, set2[j].name, set1[i].number);

                set1[i].on_hand += set2[j].on_hand;
                copies[j] = 1;
            } 
        }
    }

    for (int j = 0; j < len2; j++)
        if (copies[j] == 0)
            (*merge_set)[len++] = &set2[j];

    return len;
}

int comp_merge_set(const void *p, const void *q) {
    const struct part *p1 = *(const struct part **)p;
    const struct part *q1 = *(const struct part **)q;

    if (p1->number < q1->number)
        return -1;
    else if (p1->number > q1->number)
        return 1;
    else
        return 0;
}

void write_merge(FILE *merge_fp, struct part **merge_sets, int merge_len) {
    for (int i = 0; i < merge_len; i++)
        fwrite(merge_sets[i], sizeof(*merge_sets[i]), 1, merge_fp);
}

void terminate(const char *msg, ...) {
    // I need to read about this
    va_list(args);
    va_start(args, msg);

    vfprintf(stderr, msg, args);
    exit(EXIT_FAILURE);
}
