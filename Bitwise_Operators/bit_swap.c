#include <stdio.h>
void printBinary(int num);
int swapBits(int num, int pos1, int pos2);


// Position of bits starts from 0 
int main() {
    	int num, pos1, pos2;
	printf("Enter Number : ");
	scanf("%d",&num);
	printf("Enter Position1 : ");
	scanf("%d",&pos1);
	printf("Enter Position2 : ");
	scanf("%d",&pos2);

    int result = swapBits(num, pos1, pos2);

    printf("Before Swapping: %d - ", num);
    printBinary(num);
    printf("After  Swapping: %d - ", result);
    printBinary(result);

    return 0;
}

int swapBits(int num, int pos1, int pos2) {
    
    // Extract the values of the bits at pos1 and pos2
    int bit1 = (num >> pos1) & 1;		// 0000 or 0001
    int bit2 = (num >> pos2) & 1;		// 0000 or 0001

    // Clear the bits at pos1 and pos2
    num &= ~(1 << pos1);
    num &= ~(1 << pos2);

    // Set the bits to their swapped values
    num |= (bit1 << pos2);                      // Here bit1 will be 0 or 1
    num |= (bit2 << pos1);                      // here bit2 will be 0 or 1

    return num;
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
