#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct USER {
    char user1 ;
};

struct RRC {
    short rrc1 ;
};

struct NAS {
    char nas1 ;
};

struct SDAP {
    char sdap1 ;
};

struct PDCP {
    int pdcp1;
};

struct RLC {
    short rlc1 ;
};

struct MAC {
    short mac1 ;
};

void updateUSER(struct USER *user);
void updateRRC (struct RRC *rrc);
void updateNAS (struct NAS *nas);
void updateSDAP (struct SDAP *sdap);
void updatePDCP (struct PDCP *pdcp);
void updateRLC (struct RLC *rlc);
void updateMAC (struct MAC *mac);

int main()
{
	char *ip = "127.0.0.1";
	int port = 9666;

	struct USER user;
    struct RRC rrc;
    struct NAS nas;
    struct SDAP sdap;
    struct PDCP pdcp;
    struct RLC rlc;
    struct MAC mac;

    updateUSER(&user);
    updateRRC(&rrc);
    updateNAS(&nas);
    updateSDAP(&sdap);
    updatePDCP(&pdcp);
    updateRLC(&rlc);
    updateMAC(&mac);

	int sockfd,ret;
	struct sockaddr_in address;
	socklen_t addrlen;
	char buffer[13];
	

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

	// Copy the structs into the buffer
    char *ptr = buffer;
    memcpy(ptr, &user, sizeof(user));
    ptr += sizeof(user);
    memcpy(ptr, &rrc, sizeof(rrc));
    ptr += sizeof(rrc);
    memcpy(ptr, &nas, sizeof(nas));
    ptr += sizeof(nas);
    memcpy(ptr, &sdap, sizeof(sdap));
    ptr += sizeof(sdap);
    memcpy(ptr, &pdcp, sizeof(pdcp));
    ptr += sizeof(pdcp);
    memcpy(ptr, &rlc, sizeof(rlc));
    ptr += sizeof(rlc);
    memcpy(ptr, &mac, sizeof(mac));

	for(int i=0; i<13; i++){
		printf("In loop %d value %d\n",i,buffer[i]);
	}

	bzero(buffer,sizeof(buffer));
	send(sockfd,buffer,strlen(buffer),0);
	printf("Client sending %ld bytes of data\n",sizeof(buffer));
	close(sockfd);
	printf("Disconnected from the server.\n");
}


void updateUSER(struct USER *user){
    user->user1 = 1;
	printf("user1 : %d\n",user->user1);
}

void updateRRC (struct RRC *rrc){
    rrc->rrc1 = 2;
	printf("rrc1 : %d\n",rrc->rrc1);
}

void updateNAS (struct NAS *nas){
    nas->nas1 = 3;
	printf("nas1 : %d\n",nas->nas1);
}

void updateSDAP (struct SDAP *sdap){
    sdap->sdap1 = 4;
	printf("sdap1 : %d\n",sdap->sdap1);
}

void updatePDCP (struct PDCP *pdcp){
    pdcp->pdcp1 = 5;
	printf("pdcp1 : %d\n",pdcp->pdcp1);
}

void updateRLC (struct RLC *rlc){
    rlc->rlc1 = 6;
	printf("rlc1 : %d\n",rlc->rlc1);
}

void updateMAC (struct MAC *mac){
    mac->mac1 = 7;
	printf("mac1 : %d\n",mac->mac1);
}



