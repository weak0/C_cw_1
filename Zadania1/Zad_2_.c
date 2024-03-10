#include <stdio.h>

int main() {
    int grades[2][5] = {
            {2, 2, 3, 4, 5},
            {2, 3, 4, 5, 4}
    };

    int sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            sum += grades[i][j];
        }
    }
    int length = sizeof(grades) / sizeof(grades[0][0]);
    double avg = (double)sum / length;
    printf("Srednia ocen: %f", avg);
    return 0;
}
