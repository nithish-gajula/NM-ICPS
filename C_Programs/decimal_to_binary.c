#include <stdio.h>
void main() {
    int num = 212;
    
    for(int i=31; i>=0; i--){
        int bit = (num>>i) & 1 ;
        printf("%d",bit);

        if(i%4==0){
            printf(" ");
        }
    }
    printf("\n");
}