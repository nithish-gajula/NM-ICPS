#include <stdio.h>

int getValue(int a[],int i);

struct Dictionary {
    int key;
    int value;
} dict;

int main(){

    struct Dictionary dict[5];


    int a[5] = {10,20,30,40,50};
    int *b = a;
    int **c = &b;

    for(int i=0; i<5;i++){
        printf("value at index %d is %d\n",i,getValue(a,i));
    }

    return 0;
}

int getValue(int a[],int i){
    return *(a+i);
}