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
//    - Zdefiniuj strukturę **`Point`**, która przechowuje współrzędne punktu na płaszczyźnie (x, y).
//    Napisz funkcję, która przyjmuje wskaźnik do struktury **`Point`** i zmienia jej wartości współrzędnych.
//    Utwórz instancję **`Point`** i zmień jej współrzędne za pomocą funkcji, a następnie wypisz zmienione współrzędne
//    Następnie utwórz strukturę `Rectangle- Napisz funkcję, która przyjmuje do struktury `Rectangle` i liczy pole, obwód tej struktury.

    struct Point p = {5, 5};
    modify(&p);
    printf("x = %d, y = %d\n", p.x, p.y);

    struct Rectangle r = {{1, 1}, {5, 5}};
    calculate(&r);

return 0;
}

