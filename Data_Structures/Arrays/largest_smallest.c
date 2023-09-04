#include <stdio.h>

int largest(int arr[], int length);
int smallest(int arr[], int length);

int main(){

    int arr[] = {4,7,9,2,8,3,5,6,1};
    int length = sizeof(arr) / sizeof(arr[0]);

    largest(arr,length);
    smallest(arr,length);
    

    return 0;
}

int largest(int arr[], int length){

    int first = arr[0], second = -1, third = -1;
    printf("Largest-----------------------\n");
    for(int i=0; i<length; i++){
        if(arr[i] > first){
            third = second;
            second = first;
            first = arr[i];
            //printf("Loop %d : first : %d\n",i,first);
        } else if (arr[i] > second )
        {
            third = second;
            second = arr[i];
            //printf("Loop %d : second : %d\n",i,second);
        } else if (arr[i] > third){
            third = arr[i];
            //printf("Loop %d : third : %d\n",i,third);
        }  
    }

    
    printf("First : %d\nSecond : %d\nThird : %d\n",first,second,third);

}

int smallest(int arr[], int length){

    int first = arr[0] , second = arr[0], third = arr[0];
    printf("Smallest-----------------------\n");

    for(int i=0; i < length; i++){
        if(arr[i] < third){
            first = second;
            second = third;
            third = arr[i];
            //printf("Loop %d : third : %d\n",i,third);
        } else if (arr[i] < second){
            first = second;
            second = arr[i];
            //printf("Loop %d : second : %d\n",i,second);
        } else if (arr[i] < first){
            first = arr[i];
            //printf("Loop %d : first : %d\n",i,first);
        }
    }

    
    printf("First : %d\nSecond : %d\nThird : %d\n",first,second,third);

}