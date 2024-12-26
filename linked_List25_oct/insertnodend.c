#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end
struct Node* insertAtEnd(struct Node* head, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL; // The new node will be the last, so next is NULL

    // If the list is empty, the new node becomes the head
    if (head == NULL) {
        return newNode;
    }

    // Traverse to the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; // Link the last node to the new node

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
    int n, value;

    // Take the number of nodes as input
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Take input for each node's value
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtEnd(head, value); // Insert at the end
    }

    // Print the linked list
    printf("Linked list after inserting nodes at the end:\n");
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
