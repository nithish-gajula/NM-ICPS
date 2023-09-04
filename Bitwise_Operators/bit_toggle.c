#include <stdio.h>

int main(){

    int num = 212;
    int pos = 2;

    int mask = 1<<(pos);
    int result = num ^ mask ;

    printf("result : %d\n",result);


    return 0;
}

