#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct point {
    int x, y;
};

struct rectangle {
    struct point upper_left, lower_right;
};

int compute_area(struct rectangle r);
struct point compute_center(struct rectangle r);
struct rectangle move_rec(struct rectangle r, int x, int y);
bool is_inside(struct rectangle r, struct point p);

int main(void) {
    return 0;
}

int compute_area(struct rectangle r) {
    int len = abs(r.upper_left.x - r.lower_right.x);
    int wid = abs(r.upper_left.y - r.lower_right.y);

    return len * wid;
}

struct point compute_center(struct rectangle r) {
    struct point center;

    center.x = (r.upper_left.x + r.lower_right.x) / 2;
    center.y = (r.upper_left.y + r.lower_right.y) / 2;

    return center;
}

struct rectangle move_rec(struct rectangle r, int x, int y) {
    r.upper_left.x += x;
    r.upper_left.y += y;

    r.lower_right.x += x;
    r.lower_right.y += y;

    return r;
}

bool is_inside(struct rectangle r, struct point p) {
    return p.x > r.upper_left.x && p.x < r.lower_right.x
           && p.y < r.upper_left.y && p.y > r.lower_right.y;
}
