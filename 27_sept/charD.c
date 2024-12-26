#include <stdio.h>

int main() {
    char str[100];
    int index;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the index of the character to display: ");
    scanf("%d", &index);

    if (index >= 0 && index < strlen(str)) {
        printf("Character at index %d: %c\n", index, str[index]);
    } else {
        printf("Invalid index.\n");
    }

    return 0;
}
