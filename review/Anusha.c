#include<stdio.h>
void program1();
void program2();

int main(){

	program1();
	program2();
	
	return 0;
}

void program1(){

	int arr[] = {2,4,6,8,0,1,3,5,7,9};
	
	int length = sizeof(arr)/sizeof(arr[0]);
	
	for(int i=0; i<length; i++){
		for(int j=i+1; j<length; j++){
			if(arr[i]>arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	for(int i=0; i<length; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void program2(){

	unsigned int data = 0xAABBCCDD;
	unsigned int result = ((data<<16)&0xffff0000) | ((data>>16)&0x0000ffff) ;
	
	printf("%X\n",result);
}
