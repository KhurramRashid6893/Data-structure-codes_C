#include <stdio.h>

int main() {
    int n, deleteElement, found = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to delete: ");
    scanf("%d", &deleteElement);

    for(int i = 0; i < n; i++) {
        if(arr[i] == deleteElement) {
            found = 1;
            for(int j = i; j < n-1; j++) {
                arr[j] = arr[j+1];
            }
            break;
        }
    }

    if(found) {
        printf("Array after deletion:\n");
        for(int i = 0; i < n-1; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
