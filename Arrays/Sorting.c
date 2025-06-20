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

void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i+1; j < size; j++) {
            if(arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr+i, arr+min_index);
        }
    }
}

void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int j = i - 1;
        int key = arr[i];   // extracted element
        // move all the elements greater than key to the right side
        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        // find the correct position for key
        arr[j+1] = key;
    }
}

void merge(int *arr, int left, int mid, int right) {
    int left_size = mid - left + 1, right_size = right - mid;
    int left_arr[left_size], right_arr[right_size];

    for (int i = 0; i < left_size; i++) left_arr[i] = arr[left + i];
    for (int i = 0; i < right_size; i++) right_arr[i] = arr[mid + 1 + i];
    
    int i=0, j=0, k=left;
    while (i < left_size && j < right_size) {
        arr[k++] = (left_arr[i] <= right_arr[j]) ? left_arr[i++] : right_arr[j++];
    }

    while(i < left_size) arr[k++] = left_arr[i++];
    while(j < right_size) arr[k++] = right_arr[j++];
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);  // left subarray
        mergeSort(arr, mid+1, right); // right subarray
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int left, int right) {
    int i = (left - 1);

    int pivot = arr[right];

    int j;
    for (j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            // if current element is smaller than pivot
            i++;    // increase the index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[right]);   // place the last element i.e. the pivot to its correct position

    return (i+1);
}

void quickSort(int arr[], int left, int right) {
    if (right > left) {
        // partitioning index is returned by the partition function
        // element is at its correct position
        int partitionIndex = partition(arr, left, right);
        
        // sorting elements before and after the partition index
        quickSort(arr, left, partitionIndex-1);
        quickSort(arr, partitionIndex+1, right);
    }
}

int main() {
    int size;

    srand(time(0)); // seed random number generator

    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) - 49;
    }

    printf("\nBefore Sorting: ");
    printArray(arr, size);

    // bubbleSort(arr, size);
    // selectionSort(arr, size);
    // insertionSort(arr, size);
    // mergeSort(arr, 0, size-1);
    quickSort(arr, 0, size-1);

    printf("\nAfter Sorting: ");
    printArray(arr, size);
    
    return 0;
}