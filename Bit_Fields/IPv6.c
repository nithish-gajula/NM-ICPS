#include <stdio.h>

struct {
    unsigned int version: 4;
    unsigned int traffic_class: 8;
    unsigned int flow_label: 20;
    unsigned int payload_length: 16;
    unsigned int next_header: 8;
    unsigned int hop_limit: 8;
    unsigned int source_address[4];         // 128-bit source IPv6 address
    unsigned int destination_address[4];    // 128-bit destination IPv6 address
}IPv6_Header; // ==> (int) 4 bytes * 10 = 40 bytes



void main(){

	printf("IPv6_Header size : %ld \n", sizeof(IPv6_Header));
	
}
