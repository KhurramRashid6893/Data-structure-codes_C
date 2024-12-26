#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a queue structure
struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

// Function to initialize the queue
void initialize(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Function to enqueue an element to the queue
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d.\n", value);
    } else {
        if (q->front == -1) q->f
        0;  // Set front to 0 if queue was empty
        q->items[++q->rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue from empty queue.\n");
        return -1; // or any sentinel value to indicate error
    } else {
        return q->items[q->front++];
    }
}

// Function to display the front element of the queue
void peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No elements to peek.\n");
    } else {
        printf("Front element: %d\n", q->items[q->front]);
    }
}

// Function to display all elements in the queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No elements to display.\n");
    } else {
        printf("Elements in queue: ");
        for (int i = q->front; i <= q->rear; ++i) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);
    int choice, value;

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                value = dequeue(&queue);
                if (value != -1)
                    printf("Dequeued element: %d\n", value);
                break;
            case 3:
                peek(&queue);
                break;
            case 4:
                display(&queue);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
