#include <stdio.h>

int main() {
    int a, b;
    int sum, difference, product, quotient, remainder;

    a = 40;
    b = 56;

    // Perform arithmetic operations
    sum = a + b;
    difference = a - b;
    product = a * b;
    quotient = a / b;
    remainder = a % b;

    // Display the results
    printf("Sum: %d + %d = %d\n", a, b, sum);
    printf("Difference: %d - %d = %d\n", a, b, difference);
    printf("Product: %d * %d = %d\n", a, b, product);
    printf("Quotient: %d / %d = %d\n", a, b, quotient);
    printf("Remainder: %d %% %d = %d\n", a, b, remainder);

    return 0;
}

