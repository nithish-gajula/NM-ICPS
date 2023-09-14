#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#pragma pack(1)

struct NAS {
    unsigned char nas1: 5;
    unsigned char nas2: 3;
};

struct RRC {
    unsigned char rrc1: 5;
    unsigned char rrc2: 3;
};

struct SDAP {
    unsigned char RDI: 1;
    unsigned char RQI: 1;
    unsigned char QFI: 6;
};

struct PDCP {
    unsigned char DC: 1;
    unsigned char R: 5;
    unsigned int SN: 18; 
};

struct RLC {
    unsigned char DC: 1;
    unsigned char P: 1;
    unsigned char SI: 2;
    unsigned short int SN: 12;
    unsigned short int SO: 16;
};

struct MAC {
    unsigned char R: 1;
    unsigned char F: 1;
    unsigned char LCID: 6;
    unsigned char L;
};

struct USER {
    unsigned char user1 ;
};


void updateNAS (struct NAS *nas);
void updateRRC (struct RRC *rrc);
void updateSDAP (struct SDAP *sdap);
void updatePDCP (struct PDCP *pdcp);
void updateRLC (struct RLC *rlc);
void updateMAC (struct MAC *mac);
void updateUSER(struct USER *user);

int main()
{
	
	struct NAS nas;
    	struct RRC rrc;
    	struct SDAP sdap;
    	struct PDCP pdcp;
    	struct RLC rlc;
    	struct MAC mac;
    	struct USER user;
    	
    	updateNAS(&nas);
    	updateRRC(&rrc);
    	updateSDAP(&sdap);
    	updatePDCP(&pdcp);
    	updateRLC(&rlc);
    	updateMAC(&mac);
    	updateUSER(&user);
	
	char *ip = "192.168.11.188";
	int port = 3000;

	int sockfd,ret;
	struct sockaddr_in address;
	socklen_t addrlen;
	
	size_t total_size = sizeof(nas) + sizeof(rrc) +  sizeof(sdap) + sizeof(pdcp) + sizeof(rlc) + sizeof(mac) + sizeof(user);
	char buffer[total_size];

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("Error creating endpoint.\n");
		exit(EXIT_FAILURE);
	}
	printf("Client socket created.\n");

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr(ip);
	address.sin_port = htons(port);
	addrlen = sizeof(address);

	ret = connect(sockfd,(struct sockaddr*)&address,addrlen);
	if(ret < 0)
	{
		perror("Error connecting to the socket.\n");
		exit(EXIT_FAILURE);
	}
	printf("Socket connected.\n");
	
	char *ptr = buffer;
    	memcpy(ptr, &nas, sizeof(nas));
    	ptr += sizeof(nas);
    	memcpy(ptr, &rrc, sizeof(rrc));
    	ptr += sizeof(rrc);
    	memcpy(ptr, &sdap, sizeof(sdap));
    	ptr += sizeof(sdap);
    	memcpy(ptr, &pdcp, sizeof(pdcp));
    	ptr += sizeof(pdcp);
    	memcpy(ptr, &rlc, sizeof(rlc));
    	ptr += sizeof(rlc);
    	memcpy(ptr, &mac, sizeof(mac));
    	ptr += sizeof(mac);
    	memcpy(ptr, &user, sizeof(user));
    
    
	send(sockfd,buffer,sizeof(buffer),0);
	printf("Sent %ld bytes of data to the server\n",sizeof(buffer));

	close(sockfd);
	printf("Disconnected from the server.\n");
}

void updateNAS (struct NAS *nas){
    nas->nas1 = 1;
    nas->nas2 = 2;
}

void updateRRC (struct RRC *rrc){
    rrc->rrc1 = 3;
    rrc->rrc2 = 4;
}

void updateSDAP (struct SDAP *sdap){
    sdap->RDI = 0;
    sdap->RQI = 1;
    sdap->QFI = 15;
}

void updatePDCP (struct PDCP *pdcp){
    pdcp->DC = 0;
    pdcp->R = 15;
    pdcp->SN = 255;
}

void updateRLC (struct RLC *rlc){
    rlc->DC = 0;
    rlc->P = 1;
    rlc->SI = 0;
    rlc->SN = 15;
    rlc->SO = 255;
}

void updateMAC (struct MAC *mac){
    mac->R = 0;
    mac->F = 1;
    mac->LCID = 15;
    mac->L = 255;
}

void updateUSER(struct USER *user){
    user->user1 = 'v';
}











