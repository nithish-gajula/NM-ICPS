#include <stdio.h>

int main(){

    int arr[] = {1,2,3,4,5};
    int length = sizeof(arr) / sizeof(arr[0]);

    //int *ptr = find_reverse(arr,length);

    int loop = length / 2 ;

    // Original Array
    printf("Original : ");
    for(int i=0; i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    for(int i = 0; i < loop ; i++){
        int temp = arr[i];
        arr[i] = arr[length-1-i];
        arr[length-1-i] = temp;

        // For every loop Array
        printf("Loop %d: ",i);
        for(int i=0; i<length;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");


    }

    // Reversed Array
    printf("Reversed : ");
    for(int i=0; i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");


    return 0;
}

