#include <stdio.h>

int main() {
    for (int i = 1; i <= 200; i++) {
        if (i % 5 == 0 && i % 7 == 0) {
            printf("%d FooBar\n", i);
        } else if (i % 5 == 0) {
            printf("%d Foo\n", i);
        } else if (i % 7 == 0) {
            printf("%d Bar\n", i);
        } else {
            printf("%d\n", i);
        }
    }
    return 0;

}
