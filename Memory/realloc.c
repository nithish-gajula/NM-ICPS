#include<stdio.h>
#include<stdlib.h>

void printValues(int *arr,int start,int end);
void appendValues(int *arr,int start,int end);

int main(){
	
	int *arr;
	
	int size = 5;
	arr = (int*) malloc(size * sizeof(int));
	appendValues(arr,0,size);
	
	
	printf("After Malloc\n");
	printValues(arr,0,size);
	
	
	int new_size = 15;
	arr = (int*) realloc(arr,new_size * sizeof(int));
	appendValues(arr,size,new_size);
	
	
	printf("After Realloc\n");
	printValues(arr,size,new_size);
	
	return 0;
}

void appendValues(int *arr,int start,int end){

	if(start==0){
		for(int i=start; i<end; i++){
			arr[i] = i+1000;
		}
	} else {
		for(int i=start; i<end; i++){
			arr[i] = i+2000;
		}
		
	}

}

void printValues(int *arr,int start,int end){
	
	for(int i=start; i<end; i++){
		printf("%d\n",arr[i]);
	}
	
}
