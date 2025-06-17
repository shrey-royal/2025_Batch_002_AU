#include <stdio.h>

int main() {
    int arr[] = {0, -1, 2, -3, 1}, x= -2;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("\n(%d, %d)", i, j);
            if (arr[i] + arr[j] == x) {
                printf("\n-> (%d, %d)", arr[i], arr[j]);
                printf("\nYes");
                return 0;
            }
        }
    }
    printf("\nNo");

    return 0;
}