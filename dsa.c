#include <stdio.h>

// Function prototypes
int linearSearch(int arr[], int size, int key);


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Linear Search
    int linearSearchKey = 22;
    int linearSearchResult = linearSearch(arr, n, linearSearchKey);
    if (linearSearchResult != -1) {
        printf("Linear Search: Element %d found at index %d\n", linearSearchKey, linearSearchResult);
    } else {
        printf("Linear Search: Element %d not found\n", linearSearchKey);
    }

    return 0;
}

// Function to perform Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Element found, return its index
        }
    }
    return -1; // Element not found
}
