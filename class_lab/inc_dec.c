#include <stdio.h>

int main() {
    int a = 5, b = 5;
    int preIncrement, postIncrement, preDecrement, postDecrement;

    // Pre-increment: ++a
    preIncrement = ++a;
    // Reset a to 5
    a = 5;

    // Post-increment: a++
    postIncrement = a++;
    // Reset a to 5
    a = 5;

    // Pre-decrement: --b
    preDecrement = --b;
    // Reset b to 5
    b = 5;

    // Post-decrement: b--
    postDecrement = b--;

    // Display the results
    printf("Initial value of a and b: 5\n");
    printf("Pre-increment (++a): %d\n", preIncrement);
    printf("Post-increment (a++): %d\n", postIncrement);
    printf("Pre-decrement (--b): %d\n", preDecrement);
    printf("Post-decrement (b--): %d\n", postDecrement);

    return 0;
}
