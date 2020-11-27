#include <stdio.h>

int main(void) {
    int n1, n2, n3, n4, n5, n6, n7, n8,
        n9, n10, n11, n12, n13, n14, n15, n16;

    printf("Enter the number from 1 to 16 in any order:\n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5,
            &n6, &n7, &n8, &n9, &n10, &n11, &n12, &n13, &n14, &n15, &n16);

    printf("%2d %2d %2d %2d\n", n1, n2, n3, n4);
    printf("%2d %2d %2d %2d\n", n5, n6, n7, n8);
    printf("%2d %2d %2d %2d\n", n9, n10, n11, n12);
    printf("%2d %2d %2d %2d\n", n13, n14, n15, n16);

    int row1_sum = n1 + n2 + n3 + n4;
    int row2_sum = n5 + n6 + n7 + n8;
    int row3_sum = n9 + n10 + n11 + n12;
    int row4_sum = n13 + n14 + n15 + n16;

    int col1_sum = n1 + n5 + n9 + n13;
    int col2_sum = n2 + n6 + n10 + n14;
    int col3_sum = n3 + n7 + n11 + n15;
    int col4_sum = n4 + n8 + n12 + n16;

    int diag1_sum = n1 + n6 + n11 + n16;
    int diag2_sum = n4 + n7 + n10 + n13;

    printf("Row sums: %2d %2d %2d %2d\n", row1_sum, row2_sum, row3_sum, row4_sum);
    printf("Column sums: %2d %2d %2d %2d\n", col1_sum, col2_sum, col3_sum, col4_sum);
    printf("Diagonal sums: %2d %2d\n", diag1_sum, diag2_sum);

    return 0;
}
