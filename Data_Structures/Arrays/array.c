#include <stdio.h>

int takeSize();
void appendValues(int arr[],int length);
void printaArray(int arr[],int length);

int main(){

    int length = takeSize();

    int arr[length];
    appendValues(arr,length);
    printaArray(arr,length);
    

    return 0;
}

int takeSize(){
    int size = 0;
    printf("Enter array size : ");
    scanf("%d",&size);
    return size;
}

void appendValues(int arr[],int length){

    for(int i=0; i<length; i++){
        scanf("%d",&arr[i]);
    }

}

void printaArray(int arr[],int length){
    for(int i=0; i<length; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

