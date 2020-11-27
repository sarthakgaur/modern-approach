#include <stdio.h>

#define N 10

int main(void) {
    int ident[N][N];
    int *p;
    int count = 0;

    for (p = &ident[0][0]; p < &ident[N-1][N]; p++) {
        count = count == N + 1 ? 0 : count;
        if (count == 0) {
            *p = 1;
        } else {
            *p = 0;
        }
        count++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", ident[i][j]);
        }
        printf("\n");
    }

    return 0;
}
