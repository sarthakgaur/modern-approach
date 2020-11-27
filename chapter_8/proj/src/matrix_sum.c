#include <stdio.h>

#define SIZE 5

int main(void) {
    int row_sum[SIZE] = {0};
    int col_sum[SIZE] = {0};
    int temp;

    for (int i = 0; i < SIZE; i++) {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &temp);
            row_sum[i] += temp;
            col_sum[j] += temp;
        }
    }

    printf("\nRow totals: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", row_sum[i]);

    printf("\nColumn totals: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", col_sum[i]);

    printf("\n");

    return 0;
}
