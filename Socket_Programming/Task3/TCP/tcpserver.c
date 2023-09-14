#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
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

void printNAS (struct NAS *nas);
void printRRC (struct RRC *rrc);
void printSDAP (struct SDAP *sdap);
void printPDCP (struct PDCP *pdcp);
void printRLC (struct RLC *rlc);
void printMAC (struct MAC *mac);
void printUSER(struct USER *user);

int main()
{

	struct NAS nas;
    	struct RRC rrc;
    	struct SDAP sdap;
    	struct PDCP pdcp;
    	struct RLC rlc;
    	struct MAC mac;
    	struct USER user;
	
	char *ip = "192.168.11.188";
	int port = 3000;
	
	int server_sockfd,client_sockfd,ret;
	struct sockaddr_in server_address,client_address;
	socklen_t server_addrlen,client_addrlen;
	
	size_t total_size = sizeof(nas) + sizeof(rrc)  + sizeof(sdap) + sizeof(pdcp) + sizeof(rlc) + sizeof(mac) + sizeof(user);
	char buffer[total_size];

	server_sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(server_sockfd < 0)
	{
		perror("Error creating server endpoint.\n");
		exit(EXIT_FAILURE);
	}
	printf("Server socket created.\n");

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr(ip); 
	server_address.sin_port = htons(port);
	server_addrlen = sizeof(server_address);

	ret = bind(server_sockfd,(struct sockaddr*)&server_address,server_addrlen);
	if(ret < 0)
	{
		perror("Error binding to the server socket.\n");
		exit(EXIT_FAILURE);
	}
	printf("Server socket binded to the port number %d.\n",port);

	ret = listen(server_sockfd,1);
	if(ret < 0)
	{
		perror("Server socket not ready to accept connections.\n");
		exit(EXIT_FAILURE);
	}
	printf("Server socket ready to accept connections.\n");
	printf("Welcome to chat room.\n");
	
	client_addrlen = sizeof(client_address);
	client_sockfd = accept(server_sockfd,(struct sockaddr*)&client_address,&client_addrlen);
	if(client_sockfd < 0)
	{
		perror("Error accepting client connection.\n");
		exit(EXIT_FAILURE);
	}
	printf("Client connected.\n");
	printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
	
	recv(client_sockfd,buffer,sizeof(buffer),0);
	printf("Received %ld bytes of data from the client\n",sizeof(buffer));
	
	// Extract and print the received structs
    	char *ptr = buffer;
    	memcpy(&nas, ptr, sizeof(nas));
    	ptr += sizeof(nas);
    	memcpy(&rrc, ptr, sizeof(rrc));
    	ptr += sizeof(rrc);
    	memcpy(&sdap, ptr, sizeof(sdap));
    	ptr += sizeof(sdap);
    	memcpy(&pdcp, ptr, sizeof(pdcp));
    	ptr += sizeof(pdcp);
    	memcpy(&rlc, ptr, sizeof(rlc));
    	ptr += sizeof(rlc);
    	memcpy(&mac, ptr, sizeof(mac));
    	ptr += sizeof(mac);
    	memcpy(&user, ptr, sizeof(user));

	//close(client_sockfd);
	printf("Client Disconnected.\n");
	//close(server_sockfd);
    	
    	printf("--------------------------------\n");
    	printNAS(&nas);
    	printRRC(&rrc);
    	printSDAP(&sdap);
    	printPDCP(&pdcp);
    	printRLC(&rlc);
    	printMAC(&mac);
    	printUSER(&user);  	
    
}

void printNAS (struct NAS *nas){
    	printf("Received NAS Header\n");
    	printf("nas1 : %d\n", nas->nas1);
    	printf("nas2 : %d\n", nas->nas2);
    	printf("--------------------------------\n");
}

void printRRC (struct RRC *rrc){
    	printf("Received RRC Header\n");
    	printf("rrc1 : %d\n", rrc->rrc1);
    	printf("rrc2 : %d\n", rrc->rrc2);
    	printf("--------------------------------\n");
}

void printSDAP (struct SDAP *sdap){
    	printf("Received SDAP Header\n");
    	printf("RDI : %d\n", sdap->RDI);
    	printf("RQI : %d\n", sdap->RQI);
    	printf("QFI : %d\n", sdap->QFI);
    	printf("--------------------------------\n");
}

void printPDCP (struct PDCP *pdcp){
    	printf("Received PDCP Header\n");
    	printf("DC : %d\n", pdcp->DC);
    	printf("R  : %d\n", pdcp->R);
    	printf("SN : %d\n", pdcp->SN);
    	printf("--------------------------------\n");
}

void printRLC (struct RLC *rlc){
   	printf("Received RLC Header\n");
    	printf("DC : %d\n", rlc->DC);
    	printf("P  : %d\n", rlc->P);
    	printf("SI : %d\n", rlc->SI);
    	printf("SN : %d\n", rlc->SN);
    	printf("SO : %d\n", rlc->SO);
    	printf("--------------------------------\n");
}

void printMAC (struct MAC *mac){
    	printf("Received MAC Header\n");
    	printf("R    : %d\n", mac->R);
    	printf("F    : %d\n", mac->F);
    	printf("LCID : %d\n", mac->LCID);
    	printf("L    : %d\n", mac->L);
    	printf("--------------------------------\n");
}

void printUSER(struct USER *user){
    	printf("Received UserInput\n");
	printf("user1 : %c\n", user->user1);	
    	printf("--------------------------------\n");
}
















