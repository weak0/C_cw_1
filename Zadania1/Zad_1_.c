#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    char name[50];

    printf("Podaj swoje imie:");
    scanf("%s", name);
    printf("Witaj, %s", name);


    return 0;
}
