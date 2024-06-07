#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int (*ptr)(int, int);
    int a, b;
    char operation;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Enter operation (+, *, -): ");
    scanf(" %c", &operation);
    switch (operation) {
        case '+':
            ptr = add;
            break;
        case '*':
            ptr = multiply;
            break;
        case '-':
            ptr = subtract;
            break;
        default:
            printf("Invalid operation\n");
            return 1;
    }
    printf("Result: %d\n", ptr(a, b));
    return 0;
}