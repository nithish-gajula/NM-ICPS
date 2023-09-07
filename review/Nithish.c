#include<stdio.h>

int main(){
	
	unsigned int a = 255;
	unsigned int b = 0;
	
	
	unsigned int mask_1 = ( a >> 0 ) & 1;
	unsigned int mask_2 = ( a >> 1 ) & 1;
	//unsigned int mask_3 = ( a >> 2 ) & 1;
	//unsigned int mask_4 = ( a >> 3 ) & 1;
	
	//b = (mask_1<<3) | (mask_2<<2) | (mask_3<<1) | (mask_4<<0) ;
	//b =(mask_1<<1) | (mask_2<<0) ;
	b |= ((a<<30)>>30);
	//b|=a&0x3;
	
	printf("%d",b);

	return 0;
}
