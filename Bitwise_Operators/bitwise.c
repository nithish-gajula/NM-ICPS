#include <stdio.h>

int main(){

    int a = 212;
    int b = 2;
    printf("Bitwise And : %d\n", a & b);
    printf("Bitwise OR  : %d\n", a | b);
    printf("Bitwise XOR : %d\n", a ^ b);
    printf("Bitwise NOT : %d\n", ~a);
    printf("Left Shift  : %d\n", a >> b);
    printf("Right Shift : %d\n", a << b);
    return 0;

}