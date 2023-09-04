#include<stdio.h>
#include"./module1/funcA.h"
#include"./module2/funcB.h"
#include"./module3/funcC.h"

void main(){
	printf("This is main function\n");
	funcA();
	funcB();
	funcC();
}
