#include <stdio.h>

struct new
{
    int a;
    int b;
};

void test(struct new *p);

int main() {

    struct new p;
    test(&p);

    printf("value of a : %d\n",p.a);
    printf("value of b : %d\n",p.b);
    return 0;
}

void test(struct new *p){
    printf("Enter value of a : ");
    scanf("%d",&(p->a));
    printf("Enter value of b : ");
    scanf("%d",&(p->b));
    printf("End");
}
