#include <stdio.h>

int main(){

    float a = 10;
    float *b = &a;
    float **c = &b;
    float *d = &a;

    printf("Address of a : %p\n",&a);       // This will print the address of variable a
    printf("Address of b : %p\n",&b);       // This will print the address of pointer b
    printf("Address of c : %p\n",&c);       // This will print the address of pointer c
    printf("Value of a : %f\n",a);          // This will print the value of integer a;
    printf("Value of b : %p\n",b);          // This will print the value(address of a) of pointer b;
    printf("Value of c : %p\n",c);          // This will print the value(address of b) of pointer c;
    printf("Value of a from b : %f\n",*b);  // This will print the value of a
    printf("Value of a from c : %f\n",**c); // This will print the value of a




















    /*
    int x[4];

    for (int i = 0; i < 4; i++)
    {   
        printf("Enter %d element : ",i+i);
        scanf("%d",x+i);
        printf("Value at position %d is : %d\n",i+1,*x+i);
    }
    

    
    */


    
    
}