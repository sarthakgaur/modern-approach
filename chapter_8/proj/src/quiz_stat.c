#include <stdio.h>

#define SIZE 5
#define NOT_SET -1

int main(void) {
    int row_sum[SIZE] = {0};
    int col_sum[SIZE] = {0};
    int min_max[SIZE][2] = {0}; // 0 is min, 1 is max
    int n;

    for (int i = 0; i < SIZE; i++) {
        min_max[i][0] = NOT_SET; // initially mark min as NOT_SET

        printf("Quic %d scores: ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &n);
            row_sum[i] += n;
            col_sum[j] += n;

            if (min_max[i][0] == NOT_SET) min_max[i][0] = n; // set min if NOT_SET
            if (min_max[i][0] > n) min_max[i][0] = n; // set min value
            if (min_max[i][1] < n) min_max[i][1] = n; // set max value
        }
    }

    printf("\nStudent stats:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Student %d -> ", i);
        printf("sum: %d, ", col_sum[i]);
        printf("avg: %.2f\n", (float) col_sum[i] / SIZE);
    }

    printf("\nQuiz stats:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("quiz %d -> ", i);
        printf("avg: %.2f, ", (float) row_sum[i] / SIZE);
        printf("low: %d, ", min_max[i][0]);
        printf("hi: %d\n", min_max[i][1]);
    }

    return 0;
}
