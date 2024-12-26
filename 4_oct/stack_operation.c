#include <stdio.h>
#include <conio.h>
#define MAX 100

int stack[MAX];
int top = 0, x;

// Function declarations
void push(int);
int pop();
void display();
int isempty();
int isfull();

void main() {
    int ch, item, d;
    char a;

    printf("\n Stack Implementation");
    printf("\n --------------------");
    printf("\n1.PUSH");
    printf("\n2.POP");
    printf("\n3.Display");
    printf("\n4.IsEmpty");
    printf("\n5.IsFull");

    do {
        printf("\n\n Enter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter an Element to PUSH: \n");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                x = pop();
                printf("The element POPPED out from Stack is: %d", x);
                break;
            case 3:
                display();
                break;
            case 4:
                x = isempty();
                if (x == 1)
                    printf("Stack is Empty");
                else
                    printf("Stack is Not Empty");
                break;
            case 5:
                x = isfull();
                if (x == 1)
                    printf("Stack is Full");
                else
                    printf("Stack is Not Full");
                break;
            default:
                printf("INVALID Choice\n");
        }

        printf("\n\nDo you want to continue (y/n): ");
        scanf(" %c", &a);
    } while (a == 'y' || a == 'Y');

    getch();
}

// PUSH function
void push(int x) {
    if (top >= MAX) {
        printf("Stack Overflow\n");
    } else {
        stack[top] = x;
        top++;
    }
}

// POP function
int pop() {
    if (top <= 0) {
        printf("Stack Underflow\n");
        return -1;  // Return -1 when stack is empty
    } else {
        top--;
        return stack[top];
    }
}

// Display function
void display() {
    if (top <= 0) {
        printf("Stack is Empty\n");
    } else {
        printf("The Elements in Stack are:\n");
        for (int i = top - 1; i >= 0; i--) {
            printf(" %d\n", stack[i]);
        }
    }
}

// isempty function
int isempty() {
    return (top <= 0) ? 1 : 0;
}

// isfull function
int isfull() {
    return (top >= MAX) ? 1 : 0;
}
