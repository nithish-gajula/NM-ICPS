#include <stdio.h>

float find_avg(int arr[], int length);

int main(){

    int arr[] = {1,2,3,4,5,6,7};
    int length = sizeof(arr)/sizeof(arr[0]);
    float result = find_avg(arr,length);

    printf("average : %f\n",result);

    return 0;
}

float find_avg(int arr[], int length){

    float sum = 0;
    for(int i=0; i<length; i++){
        sum += arr[i];
    }

    return sum/length;

}