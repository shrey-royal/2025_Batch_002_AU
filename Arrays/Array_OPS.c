#include <stdio.h>

int main() {
    int a[4] = {10, 20, 30, 40};
    int i, size = sizeof(a)/sizeof(a[0]);
    int pos, value, flag=0;

    // Traversing - Read OP
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

/*  // Insertion
    printf("\nEnter pos: ");
    scanf("%d", &pos);

    for (i = 0; i < size; i++) {
        if (a[i] == 0) {
            flag = 1;
        }
    }
    
    if (pos >= size) {
        printf("Array Position is out of bounds!");
        return -1;
    }

    if (!flag) {
        printf("Array is full!");
        return -1;
    } 

    printf("Enter value that you want to insert at pos %d: ", pos);
    scanf("%d", &value);

    for (i = size-1; i >= pos; i--) {
        a[i] = a[i-1];
    }
    a[pos-1] = value;
    

    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
*/
/*  // Updation
    printf("\nEnter pos: ");
    scanf("%d", &pos);

    printf("Enter value that you want to update at pos %d: ", pos);
    scanf("%d", &value);

    a[pos-1] = value;   //updating value

    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
*/
/*  // Deletion
    printf("\nEnter pos: ");
    scanf("%d", &pos);

    // Deletion
    for (i = pos-1; i < size-1; i++) {
        a[i] = a[i+1];  // left shift
    }
    a[size-1] = 0;

    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
*/

    int *arr = calloc(5, sizeof(int));
    // ... use arr ...
    arr = realloc(arr, 10 * sizeof(int));   // resize to 10 elements

    return 0;
}