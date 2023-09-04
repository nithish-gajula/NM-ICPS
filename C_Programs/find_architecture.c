#include <stdio.h>

void main() {
    if(sizeof(void*)==4){
        printf("It is 32-bit system\n");
    } else if(sizeof(void*)==8) {
        printf("It is 64-bit system\n");
    } else {
        printf("Unable to find system architecture\n");
    }
    
}