#include <stdio.h>

void print_bin_wrapper(unsigned int n);
void print_bin(unsigned int n);
void print_reverse_bits(unsigned int n);

unsigned int reverse_bits(unsigned int n);

int main(void) {
    unsigned int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Binary representation: ");
    print_bin_wrapper(n);

    printf("Reverse Binary representation: ");
    print_reverse_bits(n);

    printf("Reverse: %d\n", reverse_bits(n));

    return 0;
}

void print_bin_wrapper(unsigned int n) {
    print_bin(n);
    putchar('\n');
}

void print_bin(unsigned int n) {
    if (n) {
        print_bin(n / 2);
        printf("%d", n % 2);
    }
}

void print_reverse_bits(unsigned int n) {
    while (n) {
        printf("%d", n % 2);
        n /= 2;
    }

    putchar('\n');
}

unsigned int reverse_bits(unsigned int n) {
    static unsigned int n2 = 0;
    static int ri = 0;

    if (n) {
        reverse_bits(n / 2);
        n2 = n2 | (n % 2 << ri); 
        ri++;
    }

    return n2;
}
