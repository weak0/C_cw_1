#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Student {
    char name[20];
    float grade;
};

struct Student students[100];

void sortStudents(struct Student *students, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (students[j].grade < students[j + 1].grade) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {

    srand(time(NULL)); // seed random generator
    for (int i = 0; i < 100; i++) {
        students[i].name[0] = (char) (rand() % 26 + 65);
        students[i].grade = (float) 2.0 + (rand() % 300 / 100.0);
    }
    sortStudents(students, 100);

    for (int i = 0; i < 100; i++) {
        printf("%d. %s: %.1f\n", i+1, students[i].name, students[i].grade);
    }

    return 0;
}