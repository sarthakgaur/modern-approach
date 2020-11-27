#include <stdio.h>
#include <stddef.h>

struct st {
    char a;
    int b[2];
    float c;
};

int main(void) {
    struct st s = {'a', {0, 1}, 1.4};

    printf("sizeof struct s: %d\n", sizeof(s));

    printf("\nsizeof struct s.a: %d\n", sizeof(s.a));
    printf("sizeof struct s.b: %d\n", sizeof(s.b));
    printf("sizeof struct s.c: %d\n", sizeof(s.c));

    int off1 = offsetof(struct st, a);
    int off2 = offsetof(struct st, b);
    int off3 = offsetof(struct st, c);

    printf("\noffsetof struct s.a: %d\n", off1);
    printf("offsetof struct s.b: %d\n", off2);
    printf("offsetof struct s.c: %d\n", off3);

    int gap1 = off2 - (off1 + sizeof(s.a));
    int gap2 = off3 - (off2 + sizeof(s.b));

    printf("\ngap1: %d\n", gap1);
    printf("gap2: %d\n", gap2);

    return 0;
}
