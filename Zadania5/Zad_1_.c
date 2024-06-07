//**Cel:** Dodawanie elementu na początek listy (add_first)
//Aby dodać element na początek listy, musimy wykonać następujące czynności:
//
//- Utworzyć nowy element i ustawić jego wartość
//- Powiązać nowy element, aby wskazywał na początek listy
//- Ustawić nagłówek listy jako nasz nowy element
//- Spowoduje to utworzenie nowego nagłówka listy z nową wartością i powiązanie z nim pozostałej części listy.

#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node *next;
};

void add_first(struct Node **head, int new_data) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void print_list(struct Node *node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node *head = NULL;
    add_first(&head, 7);
    add_first(&head, 1);
    add_first(&head, 3);
    add_first(&head, 2);
    printf("\nCreated Linked list is:");
    print_list(head);
    return 0;
}

