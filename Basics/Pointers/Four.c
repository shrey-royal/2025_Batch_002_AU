#include <stdio.h>
#include <stdlib.h> // malloc, calloc, realloc, free
#include <time.h>

int main() {
    srand(time(0)); //seed random number generator
    int size = 10;

    printf("\nEnter size: ");
    scanf("%d", &size);

    // int *p = calloc(size, sizeof(int));
    int *p = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        p[i] = rand() % 100 + 1;
    }
    
    printf("\np[%d] = { ", size);
    for (int i = 0; i < size; i++) {
        printf("%d, ", *(p+i));
    }
    printf("\b\b }");

    return 0;
}
// %u, %p, %x, %o, %X
