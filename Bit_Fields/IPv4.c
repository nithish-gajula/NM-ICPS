#include <stdio.h>

struct {
	unsigned int version: 4 ;
	unsigned int IHL: 4;
	unsigned int ToS: 8;
	unsigned int T_length:16; 		
	unsigned int Identification: 16;
	unsigned int flags : 3;
	unsigned int fragment_offset:13;	
	unsigned int Time_to_Live: 8;
	unsigned int protocol : 8;
	unsigned int header_checksum: 16;	
	unsigned int source_address: 32;	
	unsigned int destination_address: 32;	
	unsigned int options: 24;
	unsigned int padding: 8;		
} IPv4_Header; // ==> (int) 4 bytes * 6 = 24 bytes



void main(){

	printf("IPv4_Header size : %ld \n", sizeof(IPv4_Header));
	
}
