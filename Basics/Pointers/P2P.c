#include <stdio.h>
#include <stdlib.h>

int main() {
    int **p;

    // allocate memory to rows
    p = (int**)malloc(3 * sizeof(int));

    // allocate memory to cols (row by row)
    for (int i = 0; i < 3; i++) {
        p[i] = (int *)malloc(3 * sizeof(int));
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            p[i][j] = 101+(100*i)+j;
        }
    }

    printf("\np[3][3] = {\n");
    for (int i = 0; i < 3; i++) {
        printf("\t{ ");
        for (int j = 0; j < 3; j++) {
            printf("%d, ", p[i][j]);
            // printf("%d, ", *(*(p+i)+j));
        }
        printf("\b\b },\n");
    }
    printf("};");
    

    return 0;
}