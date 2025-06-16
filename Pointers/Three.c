#include <stdio.h>

int main() {
    int a[] = {101, 110, 111};
    int *p;

    // printf("\n&a[0] = %u", &a[2]);
    printf("\na = %d", *(a+1));
    printf("\na = %d", *a+1);
    printf("\na = %u", a+0);    // a[0] = a+0


    return 0;
}
// %u, %p, %x, %o, %X
