#include<stdio.h>

void swap(int *m, int *n);
void addOne(int *k);

int main(){
	int m = 10, n = 20;
	printf("Before swaping m = %d, n=%d\n",m,n);
	swap(&m,&n);
	printf("After swaping m = %d, n=%d\n",m,n);

	addOne(&m);

	printf("After addOne to m, m = %d\n",m);

	return 0;
}

void swap(int *m, int *n){

	int temp = *m;
	*m = *n;
	*n = temp;
}

void addOne(int *k){

	(*k)++;
}


