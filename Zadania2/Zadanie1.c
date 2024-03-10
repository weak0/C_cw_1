#include <stdio.h>

int main() {
    int a = 5;
    int *p = &a;
    *p = 10;
    printf("a = %d\n", a);
    printf("a = %d\n", *p);

    return 0;
}

