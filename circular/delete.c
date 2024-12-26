#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Make it circular
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Make it circular
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Function to delete a node at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;

    if (*head == NULL) { // If only one node
        *head = NULL;
    } else {
        struct Node* last = *head;
        while (last->next != temp) {
            last = last->next;
        }
        last->next = *head;
    }

    free(temp);
}

// Function to delete a node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (*head->next == *head) { // If only one node
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = (*head)->next;
    free(*head);
    *head = temp->next;
}

// Function to delete a node at a given position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    for (int i = 0; temp->next != *head && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == *head) { // If position is invalid
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete at beginning\n");
        printf("4. Delete at end\n");
        printf("5. Delete at position\n");
        printf("6. Print list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                deleteAtBeginning(&head);
                break;
            case 4:
                deleteAtEnd(&head);
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 6:
                printList(head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
