#include <stdio.h>
#include <stdbool.h>

struct color make_color(int red, int green, int blue);
int getRed(struct color c);
bool equal_color(struct color color1, struct color color2);
struct color brighter(struct color c);
struct color darker(struct color c);

int to_three(int col);
int adjust_color(int col);
void print_color(struct color c);

struct color {
    int red;
    int green;
    int blue;
};

int main(void) {
    struct color c1 = {2, 1, 2};
    struct color c2 = {2, 1, 2};

    c1 = brighter(c1);
    print_color(c1);

    printf("\n");
    c2 = darker(c2);
    print_color(c2);

    return 0;
}

struct color make_color(int red, int green, int blue) {
    red = adjust_color(red);
    green = adjust_color(green);
    blue = adjust_color(blue);

    return (struct color) {red, green, blue};
}

int getRed(struct color c) {
    return c.red;
}

bool equal_color(struct color color1, struct color color2) {
    return color1.red == color2.red
           && color1.green == color2.green
           && color1.blue == color2.blue;
}

struct color brighter(struct color c) {
    if (c.red == 0 && c.green == 0 && c.blue == 0)
        return (struct color) {3, 3, 3};

    int temp[] = {c.red, c.green, c.blue};

    for (int i = 0; i < 3; i++) {
        temp[i] = to_three(temp[i]);
        temp[i] /= 0.7f;
        temp[i] = adjust_color(temp[i]);
    }

    return (struct color) {temp[0], temp[1], temp[2]};
}

struct color darker(struct color c) {
    int temp[] = {c.red, c.green, c.blue};

    for (int i = 0; i < 3; i++)
        temp[i] *= 0.7f;

    return (struct color) {temp[0], temp[1], temp[2]};
}

int to_three(int col) {
    if (col > 0 && col < 3)
        return 3;
    return col;
}

int adjust_color(int col) {
    if (col < 0)
        return 0;
    else if (col > 255)
        return 255;
    return col;
}

void print_color(struct color c) {
    printf("Red: %d\n", c.red);
    printf("Green: %d\n", c.green);
    printf("Blue: %d\n", c.blue);
}
