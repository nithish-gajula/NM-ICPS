#include <stdio.h>

int bitStatus(int num, int pos);
void printBinary(int num);
int main(){

    int num, pos;
    
    printf("Enter Number : ");
    scanf("%d",&num);
    printBinary(num);
    printf("Enter Bit_Status Position : ");
    scanf("%d",&pos);
    
    


    if(bitStatus(num,pos)){
        printf("Bit set\n");
    } else {
        printf("Bit not set\n");
    }

    return 0;
}

int bitStatus(int num, int pos){
    int mask = 1<<(pos);
    int result = num & mask;
    return result;
}

void printBinary(int num){
	for(int i=31; i>=0; i--){
		int bit = ( num >> i ) & 1;
		printf("%d",bit);
		if(i%4==0){
			printf(" ");
		}
	}
	printf("\n");
	

}
