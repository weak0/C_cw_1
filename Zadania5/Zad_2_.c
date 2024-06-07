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

void remove_first(struct Node **head) {
    if (*head == NULL) {
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
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
    remove_first(&head);
    printf("\nCreated Linked list is:");
    print_list(head);
    return 0;
}