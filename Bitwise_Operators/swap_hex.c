/* C program to swap bytes/words of integer number.*/

#include <stdio.h>

void BBAADDCC(unsigned int data);

int main()
{
    unsigned int data = 0xAABBCDD;
    printf("data before swapping : %X\n", data);
    BBAADDCC(data);

    return 0;
}

void BBAADDCC(unsigned int data){

    unsigned int mask_AA = (data >> 8) & 0x00ff0000;

    unsigned int mask_BB = (data << 8) & 0xff000000;

    unsigned int mask_CC = (data << 8) & 0x0000ff00;

    unsigned int mask_DD = (data >> 8) & 0x000000ff;

    unsigned int result = mask_AA | mask_BB | mask_CC | mask_DD ;
    printf("data after  swapping : %X\n", result);


}

