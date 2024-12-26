#include <stdio.h>

int main() {
    int array[5];

    printf("Enter 5 values:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &array[i]);
    }

    printf("Elements stored in the array are: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

