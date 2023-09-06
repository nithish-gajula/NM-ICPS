#include<stdio.h>

struct Shop {

	int num ;

};


int main(){
	struct Shop shop;
	printf("%ld\n",sizeof(shop));
	return 0;
}
