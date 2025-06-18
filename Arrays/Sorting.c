#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


void printArray(int *arr, int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b }");
}

void swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int size;

    srand(time(0)); // seed random number generator

    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    printf("\nBefore Sorting: ");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("\nAfter Sorting: ");
    printArray(arr, size);
    
    return 0;
}