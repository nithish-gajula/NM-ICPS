#include <stdio.h>
#include "header.h"


int main(){

    int a,b;
    printf("Enter a and b values : ");
    scanf("%d %d",&a,&b);

    printf("Addition        : %d\n",addition(a,b));
    printf("Substraction    : %d\n",substraction(a,b));
    printf("Multiplication  : %d\n",multiplication(a,b));
    printf("Division        : %.2f\n",division(a,b));

    

    return 0;
}