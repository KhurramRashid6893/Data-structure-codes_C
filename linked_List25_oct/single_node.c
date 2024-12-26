#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    // Create a single node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    // Assign data to the node
    newNode->data = 10;
    newNode->next = NULL; // Set the next pointer to NULL as it's a single node

    // Display the data
    printf("Node created with data: %d\n", newNode->data);

    // Free allocated memory
    free(newNode);

    return 0;
}
