#include <stdio.h>

int find_max(int arr[], int length);
int find_min(int arr[], int length);
int find_sum(int arr[], int length);
int find_max_pointer(int arr[],int length);
void find_min_pointer(int* arr, int length);
void find_sum_pointer(int* arr, int length);

void main(){

    int arr[] = {30,40,50,10,20};
    int length = sizeof(arr)/sizeof(int);

    printf("max : %d\n",find_max(arr,length));
    printf("min : %d\n",find_min(arr,length));
    printf("sum : %d\n",find_sum(arr,length));
    printf("pointer max : %d\n",find_max_pointer(arr,length));

    find_min_pointer(arr,length);
    find_sum_pointer(arr,length);

}

int find_max(int arr[],int length){
    int max = arr[0];
    for(int i=0; i<length; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

int find_min(int arr[], int length){
    int min = arr[0];
    for(int i=0; i<length;i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    return min;
}

int find_sum(int arr[], int length){
    int sum = 0;
    for(int i=0; i<length; i++){
        sum += arr[i];
    }
    return sum;
}

int find_max_pointer(int arr[],int length){

    int max = *arr; // Initializing first element of array as maximum
    int *ptr = arr; // Initializing a pointer for interating through the all elements of array

    for(int i=0; i<length;i++){
        if(*ptr > max){
            max = *ptr;
        }
        ptr++;     
    }
    return max;
}

void find_min_pointer(int* arr, int length){

    int min = *arr;
    int *ptr = arr;

    for(int i=0; i<length; i++){
        if(*ptr < min){
            min = *ptr;
        }
        ptr++;
    }
    printf("pointer min : %d\n",min);

}

void find_sum_pointer(int* arr, int length){

    int sum = 0;
    int *ptr = arr;
      
    for(int i=0; i<length; i++){
        sum += *ptr;
        ptr++;
    }
    printf("pointer sum : %d\n",sum);

}
