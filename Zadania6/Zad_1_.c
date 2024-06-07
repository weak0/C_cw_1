#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

enum DataType {
    INT,
    FLOAT,
    CHAR
};

void printUnion(union Data data, enum DataType type) {
    switch(type) {
        case INT:
            printf("value int: %d\n", data.i);
            break;
        case FLOAT:
            printf("value float: %f\n", data.f);
            break;
        case CHAR:
            printf("value char: %c\n", data.c);
            break;
        default:
            printf("Nieznany typ danych\n");
    }
}

int main() {
    union Data data;
    data.c = 'J';
    printUnion(data, CHAR);
    data.c = 'P';
    printUnion(data, CHAR);
    data.i = 2;
    printUnion(data, INT);
    data.f = 21.37;
    printUnion(data, FLOAT);


    return 0;
}
