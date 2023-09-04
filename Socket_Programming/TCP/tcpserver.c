#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	char *ip = "127.0.0.1";
	int port = 5566;

	int server_sockfd, client_sockfd, ret;
	struct sockaddr_in server_address, client_address;
	socklen_t server_addrlen, client_addrlen;
	char buffer[1024];

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


	while(1)
	{
		bzero(buffer,1024);
		recv(client_sockfd,buffer,sizeof(buffer),0);
		printf("Client - %s\n",buffer);

		bzero(buffer,1024);
		printf("Server - ");
		scanf(" %[^\n]s",buffer);
		send(client_sockfd,buffer,sizeof(buffer),0);

	}
	close(client_sockfd);
	printf("Client Disconnected.\n");
	close(server_sockfd);
}

