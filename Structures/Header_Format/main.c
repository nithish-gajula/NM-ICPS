#include<stdio.h>
#include "protocol.h"

void main(){

	printf("Ethernet_Header size : %zu \n",sizeof(Ethernet_Header));
	printf("IPv4_Header size : %zu \n",sizeof(IPv4_Header));
	printf("UDP_Header size	: %zu \n",sizeof(UDP_Header));
	printf("TCP_Header size	: %zu \n",sizeof(TCP_Header));
	printf("ICMP_format size : %zu \n",sizeof(ICMP_format));
	printf("ARP_format size	: %zu \n",sizeof(ARP_format));
	printf("RTF_format size	: %zu \n",sizeof(RTF_format));
	printf("wifi_frame_format size : %zu \n",sizeof(wifi_frame_format));
    
}
