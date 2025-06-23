#include <stdio.h>

int main() {
    int a;
    int *ptr;   // * - indirection operator

    printf("Enter a: ");
    scanf("%d", &a);

    ptr = &a;   // & - addressof operator

    // printf("\na = %u", &a);
    // printf("\nptr = %u", ptr);
    // printf("\n&ptr = %u", &ptr);

    printf("\na = %u", a);
    printf("\n*ptr = %d", *ptr);


    return 0;
}
// %u, %p, %x, %o, %X
