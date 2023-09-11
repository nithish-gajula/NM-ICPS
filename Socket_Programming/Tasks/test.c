#include<stdio.h>
void takeUserInput();

int arr[13];
int *arrPointer = arr;

struct SDAP {
    unsigned int D_C : 1;
    unsigned int R : 1;
    unsigned int QFI: 6;

};

struct PDCP {
    unsigned int D_C : 1;
    unsigned int R : 1;
    unsigned int QFI: 6;

};


int main(){

    takeUserInput();


    return 0;
}

void updateSDAP(){
    struct SDAP sdap;
    sdap.D_C = 0;   // 0 - control PDU, 1 - data PDU
    sdap.R = 0;     // Reserved bit
    sdap.QFI = 63;  // 64 QFI

}