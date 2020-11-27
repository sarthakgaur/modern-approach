#include <stdio.h>

int main(void) {
    int n1, n2, n3, n4;

    printf("Enter four integers: ");
    scanf("%d%d%d%d", &n1, &n2, &n3, &n4);

    int t;

    if (n1 > n2) {
       t = n1;
       n1 = n2;
       n2 = t;
    }

    if (n2 > n3) {
       t = n2;
       n2 = n3;
       n3 = t;
    }
    
    if (n3 > n4) {
       t = n3;
       n3 = n4;
       n4 = t;
    }

    if (n3 < n2) {
       t = n2;
       n2 = n3;
       n3 = t;
    }

    if (n2 < n1) {
       t = n1;
       n1 = n2;
       n2 = t;
    }

    printf("Largest: %d\n", n4);
    printf("Smallest: %d\n", n1);

    return 0;
}
