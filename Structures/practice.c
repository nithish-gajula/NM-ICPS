#include<stdio.h>

struct practice2
{
    short a: 8;
    short b: 9;
    
};

struct practice1
{
    int a;
    int b;
    int c;
    struct practice2 p;
};

struct practice
{ 

    char a[50];
    int b;
    struct practice1 p;

};






int main(){

    struct practice p;

    printf("%zu\n",sizeof(struct practice));


        
    

    return 0;
}
