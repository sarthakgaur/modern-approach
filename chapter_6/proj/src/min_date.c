#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int m, d, y;
    int tm, td, ty;

    bool first = true;

    while (true) {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d /%d /%d", &tm, &td, &ty);

        if (tm == 0 && td == 0 && ty == 0)
            break;

        if (first) {
            m = tm, d = td, y = ty;
            first = false;
            continue;
        }

        if (ty < y)
            m = tm, d = td, y = ty;
        else if (ty > y)
            continue;
        else if (tm < m)
            m = tm, d = td, y = ty;
        else if (tm > m)
            continue;
        else if (td < d)
            m = tm, d = td, y = ty;
    }

    printf("%.2d/%.2d/%.2d is the earliest date\n", m, d, y);

    return 0;
}
