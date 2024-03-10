#include <stdio.h>

int main() {
    int max = 500;
    int intArray[500] = {0};
    int liczba;
    printf("Podaj liczbe MAX 500: ");
    scanf("%d", &liczba);

    if (liczba < 0 || liczba > 500) {
        printf("Liczba musi byc wieksza od 0 mniejsza od 500");
        return 0;
    }

    for (int i = liczba; i > 0; i--) {
        if (i % 3 == 0 || i % 5 == 0) {
            intArray[i] = i;
        }
    }

    int sum = 0;
    for (int i = 0; i < liczba; i++) {
        sum += intArray[i];
    }
    printf("Suma liczb podzielnych przez 3 lub 5 to: %d", sum);
    return 0;
}