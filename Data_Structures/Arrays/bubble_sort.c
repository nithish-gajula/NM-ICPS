#include<stdio.h>
void printArray(int arr[],int length);
void Ascending(int arr[],int length);
void Descending(int arr[], int length);

int main(){
	int arr[] = {10,30,50,40,20,5,4,3,2,1};
	int length = sizeof(arr)/sizeof(arr[0]);
	
	Ascending(arr,length);
	Descending(arr,length);
	printArray(arr,length);
	
	return 0;
}

void printArray(int arr[],int length){
	for(int i=0; i<length; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void Ascending(int arr[],int length){

	for(int i=0; i<length-1;i++){
		for(int j=i+1; j<=length-1;j++){
			if(arr[i] >= arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}

void Descending(int arr[], int length){

	for(int i=0; i<length-1;i++){
		for(int j=i+1; j<=length-1;j++){
			if(arr[i] <= arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}
