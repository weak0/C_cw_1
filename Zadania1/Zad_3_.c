#include <stdio.h>

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        int result = 1;
        for (int j = 1; j <= array[i]; j++) {
            result *= j;
        }
        int xd = i + 1;
        printf("Silnia dla %d to %d\n", xd, result);
    }
    return 0;
}
