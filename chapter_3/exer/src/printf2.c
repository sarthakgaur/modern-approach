#include <stdio.h>

int main(void)
{
    printf("%-8.1e\n", 123.456);
    printf("%10.6e\n", 123.456);
    printf("%-8.3f\n", 123.456);
    printf("%6.0f\n", 123.456);

    return 0;
}
