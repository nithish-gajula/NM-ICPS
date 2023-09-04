#include <stdio.h>

void main() {
    int a = 10;
    float b1 = 20;
    float b2 = 30.7;
    char c = 'c';           // character should be within single quotes
    char *d = "nithish";    // string should be within double quotes
    char da[10] = "array";  
    double e = 34.56;
    
    printf("%d\n",a);       // %d is used for integers
    printf("%f\n",b1);      // %f is used for floating points
    printf("%.3f\n",b2);    // %.nf is used for floating point with n number of decimal points
    printf("%c\n",c);       // %c is used for character
    printf("%s\n",d);       // %s is used for string literals
    printf("%lf\n",e);      // %lf is used for double 

    printf("%lu\n",sizeof(d));



}