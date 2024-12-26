#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at any position
struct Node* insertAtPosition(struct Node* head, int position, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    // If inserting at the beginning
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    // Traverse to the node before the desired position
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is beyond the length of the list
    if (temp == NULL) {
        printf("Position out of bounds. Node not inserted.\n");
        free(newNode);
        return head;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize the linked list as empty
    int n, position, value;

    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);

    // Take input for each node's value and position
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        printf("Enter position for node %d: ", i + 1);
        scanf("%d", &position);
        head = insertAtPosition(head, position, value); // Insert at the specified position
    }

    // Print the linked list
    printf("Linked list after inserting nodes:\n");
    printList(head);

    // Free the allocated memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
