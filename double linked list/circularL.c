#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a circular linked list
void createCircularLinkedList(struct Node** head_ref, int n) {
    struct Node* last = NULL;
    struct Node* temp = NULL;

    // Create the first node
    *head_ref = newNode(1);
    last = *head_ref;
    temp = *head_ref;

    // Create remaining nodes and link them
    for (int i = 2; i <= n; i++) {
        temp->next = newNode(i);
        temp = temp->next;
    }

    // Connect the last node to the first node to form a circular list
    temp->next = *head_ref;
}

// Function to print the circular linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n = 5; // Number of nodes in the circular linked list

    createCircularLinkedList(&head, n);

    printf("Circular Linked List: ");
    printList(head);

    return 0;
}
