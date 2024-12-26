#include <stdio.h>

int main() {
    int n, searchElement, found = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &searchElement);

    for(int i = 0; i < n; i++) {
        if(arr[i] == searchElement) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Element not found in the array.\n");
    }

    return 0;
}
