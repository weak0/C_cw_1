#include <stdio.h>
struct Point {
    int x;
    int y;
};

void modify(struct Point *p) {
    p->x = 10;
    p->y = 20;
}

struct Rectangle {
    struct Point p1;
    struct Point p2;
};

void calculate(struct Rectangle *r) {
    int a = r->p2.x - r->p1.x;
    int b = r->p2.y - r->p1.y;
    printf("Pole: %d\n", a * b);
    printf("Obwod: %d\n", 2 * (a + b));
};

int main() {
    struct Point p = {5, 5};
    modify(&p);
    printf("x = %d, y = %d\n", p.x, p.y);

    struct Rectangle r = {{1, 1}, {5, 5}};
    calculate(&r);

return 0;
}

