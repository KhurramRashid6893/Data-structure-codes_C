#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to delete the first node
void deleteFirstNode(Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    printf("First node deleted.\n");
}

// Function to delete the last node
void deleteLastNode(Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) { // Only one node
        *head = NULL;
        free(temp);
        printf("Last node deleted.\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("Last node deleted.\n");
}

// Function to delete a node at a specific position
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        deleteFirstNode(head);
        return;
    }
    Node* temp = *head;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position exceeds the size of the list.\n");
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
    printf("Node at position %d deleted.\n", position);
}

// Function to display the doubly linked list
void displayList(Node* head) {
    Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the end (for testing and building the list)
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Main function
int main() {
    Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at End (for building the list)\n");
        printf("2. Delete First Node\n");
        printf("3. Delete Last Node\n");
        printf("4. Delete Node at Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                deleteFirstNode(&head);
                break;
            case 3:
                deleteLastNode(&head);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
