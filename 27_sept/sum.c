#include <stdio.h>

int main() {
    int numbers[10];  // Array to store 10 numbers
    int sum = 0;

    // Taking user input for the array elements
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Calculating the sum of the numbers
    for (int i = 0; i < 10; i++) {
        sum += numbers[i];
    }

    // Displaying the sum
    printf("Sum of the entered numbers: %d\n", sum);

    return 0;
}
