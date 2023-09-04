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
  int port = 9666;

  int sockfd;
  struct sockaddr_in addr;
  char buffer[200];
  socklen_t addrlen;

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sockfd < 0)
  {
	  perror("Error creating endpoint.\n");
	  exit(EXIT_FAILURE);
  }
  printf("Client socket created.\n");
  
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(ip);
  addrlen = sizeof(addr);

  while(1)
  {

  	bzero(buffer, sizeof(buffer));
  	printf("Client - ");
	scanf(" %[^\n]s",buffer);
  	sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&addr,addrlen);
  	printf("Client sending %d bytes of data\n",strlen(buffer));

  	bzero(buffer, sizeof(buffer));
  	recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, &addrlen);
	printf("Server - %s\n",buffer);
	printf("Client received %d bytes of data\n",strlen(buffer));
  }

  return 0;

}
