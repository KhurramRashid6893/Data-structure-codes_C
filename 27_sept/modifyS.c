#include <stdio.h>
#include <string.h>

int main() {
    char str[100];  // Declare a string (character array) with a maximum size of 100
    int pos;        // Variable to store the position of the character to modify
    char newChar;   // Variable to store the new character

    // Input the string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character from fgets input (if present)
    str[strcspn(str, "\n")] = 0;

    // Input the position of the character to modify
    printf("Enter the position of the character to modify (starting from 0): ");
    scanf("%d", &pos);

    // Input the new character
    printf("Enter the new character: ");
    scanf(" %c", &newChar);  // Notice the space before %c to consume any leftover newline

    // Check if the position is within bounds
    if (pos >= 0 && pos < strlen(str)) {
        str[pos] = newChar;  // Modify the character at the specified position
        printf("Modified string: %s\n", str);
    } else {
        printf("Invalid position!\n");
    }

    return 0;
}
