#include <stdio.h>
#include <string.h>  // Include the string library for strcmp

int main() {
    char str1[100], str2[100];

    // Input for first string
    printf("Enter the first string: ");
    gets(str1);  // Use fgets for safer input in larger programs

    // Input for second string
    printf("Enter the second string: ");
    gets(str2);

    // Compare the two strings
    int result = strcmp(str1, str2);

    if (result == 0) {
        printf("The strings are equal.\n");
    } else if (result > 0) {
        printf("The first string is greater than the second string.\n");
    } else {
        printf("The second string is greater than the first string.\n");
    }

    return 0;
}
