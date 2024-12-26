#include <stdio.h>

int main() {
    int num, sum = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0) {
        remainder = num % 10;  // Get the last digit
        sum += remainder;      // Add the digit to the sum
        num /= 10;             // Remove the last digit
    }

    printf("Sum of the digits: %d\n", sum);

    return 0;
}

