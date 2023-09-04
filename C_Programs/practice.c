#include <stdio.h> 

int isBitSet(int num, int pos);

void main() {

    int num = 10;
    int pos = 7;

    for(int i=31;i>=0;i--){
        int bit = (num>>i) & 1 ;
        if(isBitSet(num,i+1)){
            printf("%d %d : True\n",i,bit);
        } else {
            printf("%d %d : False\n",i,bit);
        }
    }


}

int isBitSet(int num, int pos){
    int mask = 1<<(pos-1);
    int bit_set = num & mask;
    
    if(bit_set){
        return 1;
    } else {
        return 0;
    }
}