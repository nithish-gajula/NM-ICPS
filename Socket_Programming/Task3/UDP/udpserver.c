#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	char *ip = "127.0.0.1";
	int port = 5566;

	int sockfd,ret;
	struct sockaddr_in server_address,client_address;
	socklen_t server_addrlen,client_addrlen;
	char buffer[1024];

	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd < 0)
	{
		perror("Error creating the endpoint.\n");
		exit(EXIT_FAILURE);
	}
	printf("Server socket created.\n");

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr(ip);
	server_address.sin_port = htons(port);
	server_addrlen = sizeof(server_address);

	ret = bind(sockfd,(struct sockaddr*)&server_address,server_addrlen);
	if(ret < 0)
	{
		perror("Error binding to the server socket.\n");
		exit(EXIT_FAILURE);
	}
	printf("Server socket binded to the port %d.\n",port);

	client_addrlen = sizeof(client_address);


	while(1)
	{
		bzero(buffer,1024);
		recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&client_address,&client_addrlen);
		printf("Client - %s\n",buffer);

		bzero(buffer,1024);
		printf("Sever - ");
		scanf(" %[^\n]s",buffer);
		sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&client_address,client_addrlen);
	}
	return 0;
}



