#include<stdio.h>

int fact(int n);

int main(){


    int result = fact(5);
    printf("factorial : %d\n",result);

    return 0;
}

int fact(int n){
    if(n==1){
        return 1;
    } else {
        return n * fact(n-1);
    }
    
}