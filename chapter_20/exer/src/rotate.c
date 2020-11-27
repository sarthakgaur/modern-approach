#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main(void) {
    unsigned int i;

    printf("Enter a hexadecimal number: ");
    scanf("%x", &i);

    printf("start: %x\n", i);

    printf("Rotate left: %x\n", rotate_left(i, 4));
    printf("Rotate right: %x\n", rotate_right(i, 4));

    return 0;
}

// should have used the sizeof operator
unsigned int rotate_left(unsigned int i, int n) {
    return (i << n) | (i >> 32 - n);
}

unsigned int rotate_right(unsigned int i, int n) {
    return (i >> n) | (i << 32 - n);
}
