#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

void printArray(int *arr, int size) {
    printf("\nArray elements: { ");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\b\b }");
}

int linearSearch(int *arr, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size;

    srand(time(0)); // seed random number generator

    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    int arr[size], k;

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    printArray(arr, size);

    printf("\nEnter key: ");
    scanf("%d", &k);

    int result = linearSearch(arr, size, k);

    if (result != -1) {
        printf("\n%d found at %d index", k, result);
    } else {
        printf("\n%d not found", k);
    }

    return 0;
}