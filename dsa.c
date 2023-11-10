#include <stdio.h>

// Function prototypes
int linearSearch(int arr[], int size, int key);
void bubbleSort(int arr[], int size);
int binarySearch(int arr[], int size, int key);

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Linear Search
    int linearSearchKey = 22;
    int linearSearchResult = linearSearch(arr, n, linearSearchKey);
    if (linearSearchResult != -1) {
        printf("Linear Search: Element %d found at index %d\n", linearSearchKey, linearSearchResult);
    } else {
        printf("Linear Search: Element %d not found\n", linearSearchKey);
    }

    // Bubble Sort
    bubbleSort(arr, n);
    printf("After Bubble Sort: ");
    printArray(arr, n);

    // Binary Search
    int binarySearchKey = 22;
    int binarySearchResult = binarySearch(arr, 0, n - 1, binarySearchKey);
    if (binarySearchResult != -1) {
        printf("Binary Search: Element %d found at index %d\n", binarySearchKey, binarySearchResult);
    } else {
        printf("Binary Search: Element %d not found\n", binarySearchKey);
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

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Binary Search (requires a sorted array)
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Element found, return its index
        }

        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Element not found
}

