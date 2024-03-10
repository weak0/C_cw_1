#include <stdio.h>
void modify(float *a) {
    *a *= 2;
}

int main() {
    float a = 5.5;
    modify(&a);
    printf("a = %f\n", a);

    return 0;
}

