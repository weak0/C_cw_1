#include <stdio.h>

struct Contact {
    char name[20];
    char surname[20];
    char phone[20];
};

struct Contact contacts[100];
int contactsCount = 0;

void copyString(char destination[20], char source[20]) {
    int i = 0;
    while ((destination[i] = source[i]) != '\0')
        ++i;
}

int compareString(char str1[20], char str2[20]) {
    int i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0' || str2[i] == '\0')
            break;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        return 0;
    else
        return -1;
}

void addContact(char name[20], char surname[20], char phone[20]) {
    copyString(contacts[contactsCount].name, name);
    copyString(contacts[contactsCount].surname, surname);
    copyString(contacts[contactsCount].phone, phone);
    contactsCount++;
}

void findContact(char surname[20]) {
    for (int i = 0; i < contactsCount; i++) {
        if (compareString(contacts[i].surname, surname) == 0) {
            printf("Name: %s, Surname: %s, Phone: %s\n", contacts[i].name, contacts[i].surname, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found\n");
}

void removeContact(char surname[20]) {
    for (int i = 0; i < contactsCount; i++) {
        if (compareString(contacts[i].surname, surname) == 0) {
            for (int j = i; j < contactsCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contactsCount--;
            return;
        }
    }
    printf("Contact not found\n");
}

void printContacts() {
    for (int i = 0; i < contactsCount; i++) {
        printf("Name: %s, Surname: %s, Phone: %s\n", contacts[i].name, contacts[i].surname, contacts[i].phone);
    }
}

int main() {
    int choice;
    char name[20];
    char surname[20];
    char phone[20];

    while (1) {
        printf("1. Add contact\n");
        printf("2. Find contact\n");
        printf("3. Remove contact\n");
        printf("4. Print contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter surname: ");
                scanf("%s", surname);
                printf("Enter phone: ");
                scanf("%s", phone);
                addContact(name, surname, phone);
                break;
            case 2:
                printf("Enter surname: ");
                scanf("%s", surname);
                findContact(surname);
                break;
            case 3:
                printf("Enter surname: ");
                scanf("%s", surname);
                removeContact(surname);
                break;
            case 4:
                printContacts();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}