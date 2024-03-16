#include <stdio.h>
#include <stdlib.h>

void printPascalTriangle(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    for (int line = 1; line <= n; line++) {
        int C = 1;
        for (int i = 1; i <= line; i++) {
            printf("%d ", C);
            C = C * (line - i) / i;
        }
        printf("\n");
    }
    free(arr);
}


int main() {
    int n = 10;
    printPascalTriangle(n);

    return 0;
}