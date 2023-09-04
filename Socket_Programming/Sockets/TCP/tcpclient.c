#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	char *ip = "127.0.0.1";
	int port = 9666;

	int sockfd,ret;
	struct sockaddr_in address;
	socklen_t addrlen;
	char buffer[200];
	

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

	while(1)
	{
		bzero(buffer,sizeof(buffer));
		printf("Client - ");
		scanf(" %[^\n]s",buffer);
		send(sockfd,buffer,strlen(buffer),0);
		printf("Client sending %ld bytes of data\n",strlen(buffer));

		bzero(buffer,sizeof(buffer));
		recv(sockfd,buffer,sizeof(buffer),0);
		printf("Server - %s\n",buffer);
		printf("Client received %ld bytes of data\n",strlen(buffer));
	}
	close(sockfd);
	printf("Disconnected from the server.\n");
}

