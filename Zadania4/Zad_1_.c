#include <stdio.h>
int factorial(int x) {
    if (x == 0) {
        return 1;
    }
    return x * factorial(x -1);
}

int main() {
    int x = 5;
    printf("Factorial of %d is %d\n", x, factorial(x));
    return 0;
}