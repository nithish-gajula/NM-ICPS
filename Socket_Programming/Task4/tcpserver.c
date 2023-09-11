#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct USER {
    char user1;
};

struct RRC {
    short rrc1;
};

struct NAS {
    char nas1;
};

struct SDAP {
    char sdap1;
};

struct PDCP {
    int pdcp1;
};

struct RLC {
    short rlc1;
};

struct MAC {
    short mac1;
};

struct USER user;
struct RRC rrc;
struct NAS nas;
struct SDAP sdap;
struct PDCP pdcp;
struct RLC rlc;
struct MAC mac;


int main()
{
	char *ip = "127.0.0.1";
	int port = 9666;

	int server_sockfd,client_sockfd,ret;
	struct sockaddr_in server_address,client_address;
	socklen_t server_addrlen,client_addrlen;
	char buffer[13];

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


	bzero(buffer,sizeof(buffer));
	recv(client_sockfd,buffer,sizeof(buffer),0);
	printf("Server received %ld bytes of data\n",strlen(buffer));

	for(int i=0; i<13; i++){
		printf("In loop %d value %d\n",i,buffer[i]);
	}


	char *ptr = buffer;

    memcpy(&user, ptr, sizeof(user));
	printf("buffer user : %d\n",buffer[0]);
    ptr += sizeof(user);
    memcpy(&rrc, ptr, sizeof(rrc));
    ptr += sizeof(rrc);
    memcpy(&nas, ptr, sizeof(nas));
    ptr += sizeof(nas);
    memcpy(&sdap, ptr, sizeof(sdap));
    ptr += sizeof(sdap);
    memcpy(&pdcp, ptr, sizeof(pdcp));
    ptr += sizeof(pdcp);
    memcpy(&rlc, ptr, sizeof(rlc));
    ptr += sizeof(rlc);
    memcpy(&mac, ptr, sizeof(mac));
    

    printf("--------------------------------\n");
    printf("Received UserInput\n");
    printf("user1 : %d\n", user.user1);
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("Received RRC Header\n");
    printf("rrc1 : %d\n", rrc.rrc1);
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("Received NAS Header\n");
    printf("nas1 : %d\n", nas.nas1);
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("Received SDAP Header\n");
    printf("sdap1 : %d\n", sdap.sdap1);
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("Received PDCP Header\n");
    printf("pdcp1 : %d\n", pdcp.pdcp1);
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("Received RLC Header\n");
    printf("rlc1 : %d\n", rlc.rlc1);
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("Received MAC Header\n");
    printf("mac1 : %d\n", mac.mac1);
    printf("--------------------------------\n");


	close(client_sockfd);
	printf("Client Disconnected.\n");
	close(server_sockfd);
}

