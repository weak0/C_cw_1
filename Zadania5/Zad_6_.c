//Dodawanie elementu na określonym indeksie (add_at_index)

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

void add_at_index(struct Node **head, int index, int new_data) {
    if (index == 0) {
        add_first(head, new_data);
        return;
    }
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = new_data;
    struct Node *temp = *head;
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void print_list(struct Node *node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node *head = NULL;
    add_first(&head, 3);
    add_first(&head, 2);
    add_first(&head, 1);
    add_at_index(&head, 3, 4);
    printf("\nCreated Linked list is:");
    print_list(head);
    return 0;
}