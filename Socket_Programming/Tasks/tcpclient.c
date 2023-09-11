#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
void takeUserInput();

char buffer[1024];

enum Bool {
	False,
	True
};

struct USER{
	unsigned int a : 8;
};

struct RRC{
	unsigned int a : 16;
};

struct NAS{
	unsigned int a : 8;
};

struct SDAP{
	unsigned int a : 8;
};

struct PDCP{
	unsigned int a;
};

struct RLC{
	unsigned int a : 16;
};

struct MAC{
	unsigned int a : 16;
};



int main()
{
	char *ip = "127.0.0.1";
	int port = 5566;

	int sockfd,ret;
	struct sockaddr_in address;
	socklen_t addrlen;
	

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

	if(True)
	{
		bzero(buffer,1024);
		printf("Client - ");
		//scanf(" %[^\n]s",buffer);
		takeUserInput();
		send(sockfd,buffer,sizeof(buffer),0);

	}
	close(sockfd);
	printf("Disconnected from the server.\n");
}

void takeUserInput(){

    printf("Enter anything that is of 1 byte : ");
    scanf("%d",&buffer);
    printf("You entered : %d\n",buffer);
}

void updateUser(){
	struct USER user;
	user.a = 1;


	
}

void updateRRC(){
	struct RRC rrc;
	rrc.a = 2;
	
}

void updateNAS(){
	struct NAS nas;
	nas.a = 3;
	
}

void updateSDAP(){
	struct SDAP sdap;
	sdap.a = 4;
	
}

void updatePDCP(){
	struct PDCP pdcp;
	pdcp.a = 5;
	
}

void updateRLC(){
	struct RLC rlc;
	rlc.a = 6;
	
}

void updateMAC(){
	struct MAC mac;
	mac.a = 7;
	
}



