#include <stdio.h>

int main(void) {
    char *tens[] = {"ten", "twenty", "thirty", "fourty", "fifty", 
                   "sixty", "seventy", "eighty", "ninety"};

    char *teens[] = {"eleven", "twelve", "thirteen", "fourteen",
                      "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    char *ones[] = {"one", "two", "three", "four", "five", "six", "seven"
                    "eight", "nine"};

    int n;
    printf("Enter a two-digit number: ");
    scanf("%d", &n);

    printf("You entered the number ");

    if (n > 10 && n < 20) {
        printf("%s.\n", teens[n - 10 - 1]);
        return 0;
    }

    int ntens = n / 10;
    int unit = n % 10;

    printf("%s", tens[ntens - 1]);

    if (unit == 0) {
        printf(".\n");
        return 0;
    }

    printf("-%s.\n", ones[unit - 1]);
    return 0;
}
