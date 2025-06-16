#include <stdio.h>

int main() {
    int a = 2, b = 7, c = 9;
    int *p;

    p = &a; // p point towards a
    printf("\na = %d", *p);
    printf("\n&a = %u", p);

    p = &b; // p refer the b
    printf("\nb = %d", *p);
    printf("\n&b = %u", p);

    p = &c;
    printf("\nc = %d", *p);
    printf("\n&c = %u", p);


    return 0;
}
// %u, %p, %x, %o, %X
