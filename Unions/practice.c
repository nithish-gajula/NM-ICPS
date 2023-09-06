#include<stdio.h>

struct Shop {

	union  {
		double price;
		char *title;
		char *author;
		int num_pages;
	}Book;
	
	union {
		int color;
		int size;
		char *design;
		double price;
	}Shirt;

};


int main(){
	struct Shop shop;
	printf("%ld\n",sizeof(shop.Book));
	printf("%ld\n",sizeof(shop.Book.title));
	return 0;
}
