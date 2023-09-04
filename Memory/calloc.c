#include <stdio.h>
#include <stdlib.h>

struct practice{
    int a;
    int b;
};

void printValues(struct practice *p);

int main(){
    struct practice *p;
    p = (struct practice*) calloc(1,sizeof(struct practice));

    free(p);

    printf("Before Initializing values\n");

    printValues(p);

    p->a = 10;
    p->b = 20;
    printf("After Initializing values\n");
    printValues(p);


    return 0;
}

void printValues(struct practice *p){
    printf("value of a : %d\n",p->a);
    printf("value of b : %d\n",p->b);
}