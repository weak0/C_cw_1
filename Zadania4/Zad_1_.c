//Cel: Zdefiniuj nową funkcję o nazwie factorial(), która obliczy czynnik przez rekurencyjne mnożenie (5! = 5 x 4 x 3 x 2 x 1).
//Zauważ, że zgodnie z konwencją, czynnik 0 jest równy 1 (0! = 1).

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