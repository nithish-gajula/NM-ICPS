#include <stdio.h>
#include <stdlib.h>

struct practice{
    int a;
    int b;
};

void printValues(struct practice *p);

int main(){
    struct practice *p;
    p = (struct practice*) malloc(sizeof(struct practice));

    p->a = 10;
    p->b = 20;

    printValues(p);

    return 0;
}

void printValues(struct practice *p){
    printf("value a : %d\n",p->a);
    printf("value a : %d\n",p->b);
}