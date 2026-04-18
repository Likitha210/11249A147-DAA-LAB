#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array
int partition_left(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

// Function to perform random partition
int partition_right(int arr[], int low, int high) {
    int r = low + rand() % (high - low + 1); // FIXED
    swap(&arr[r], &arr[high]);
    return partition_left(arr, low, high);
}

// Recursive function for quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition_right(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
    srand(time(NULL)); // MOVED HERE

    int arr[] = { 6, 4, 12, 8, 15, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
