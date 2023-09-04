#include <stdio.h>
void printBinary(int num);
int main(){

    int num, pos;
    
    printf("Enter Number : ");
    scanf("%d",&num);
    printBinary(num);
    printf("Enter Bit_Clear Position : ");
    scanf("%d",&pos);
    

    int mask = 1 << pos;
    int invert = ~mask;
    int result = num & invert ;

    printf("result : %d\n",result);
    printBinary(result);


    return 0;
}

void printBinary(int num){

	for(int i= 31; i>=0; i--){
		int bit = (num >> i) & 1;
		printf("%d",bit);
		if(i%4==0){
			printf(" ");
		}
	}
	printf("\n");

}
