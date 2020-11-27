#include <stdio.h>

#define RECTANGLE 0
#define CIRCLE 1
#define PI 3.1415

struct point {
    int x, y;
};

struct shape {
    int shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

double area(struct shape s);
struct shape move(struct shape s, int x, int y);
struct shape scale(struct shape s, double c);

int main(void) {
    return 0;
}

double area(struct shape s) {
    if (s.shape_kind == RECTANGLE)
        return s.u.rectangle.height * s.u.rectangle.width;
    else if (s.shape_kind == CIRCLE)
        return PI * s.u.circle.radius * s.u.circle.radius;
}

struct shape move(struct shape s, int x, int y) {
    s.center.x += x;
    s.center.y += y;

    return s;
}

struct shape scale(struct shape s, double c) {
    if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height *= c;
        s.u.rectangle.width *= c;
    } else if (s.shape_kind == CIRCLE) {
        s.u.circle.radius *= c;
    }
    
    return s;
}
