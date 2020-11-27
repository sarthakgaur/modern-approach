#include <stdio.h>

int main(void) {
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");

    int n;
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    int magic_square[n][n];

    // set all elements to zero
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magic_square[i][j] = 0;

    // initial x and y coordinates
    int x = 0;
    int y = n / 2;

    // old x and y coordinates
    int ox, oy;

    int i = 1;
    while (i <= n * n) {
        magic_square[x][y] = i;
        ox = x, oy = y;

        // decrease x and increase y 
        x--;
        y++;

        // wrap around x and y
        if (x < 0) x = n - 1;
        if (y > n - 1) y = 0;

        if (magic_square[x][y] != 0)
            x = ox + 1, y = oy;

        i++;
    }

    // print the magic square
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d  ", magic_square[i][j]);
        }
        printf("\n");
    }

    return 0;
}
