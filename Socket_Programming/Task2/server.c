#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#pragma pack(1)

struct NAS {
    unsigned char nas1:5;
    unsigned char nas2:3;
};

struct RRC {
    unsigned char rrc1:5;
    unsigned char rrc2:3;
};

struct SDAP {
    unsigned char RDI: 1;
    unsigned char RQI: 1;
    unsigned char QFI: 6;
};

struct PDCP {
    unsigned char DC: 1;
    unsigned char R: 5;
    unsigned int SN:18;
};

struct RLC {
    unsigned char DC: 1;
    unsigned char P: 1;
    unsigned char SI: 2;
    unsigned short int SN:12;
    unsigned short int SO:16;
};

struct MAC {
    unsigned char R: 1;
    unsigned char F: 1;
    unsigned char LCID: 6;
    unsigned char L;
};

struct USER {
    unsigned char user1 : 8;
};

struct NAS nas;
struct RRC rrc;
struct SDAP sdap;
struct PDCP pdcp;
struct RLC rlc;
struct MAC mac;
struct USER user;


void printNAS (struct NAS *nas);
void printRRC (struct RRC *rrc);
void printSDAP (struct SDAP *sdap);
void printPDCP (struct PDCP *pdcp);
void printRLC (struct RLC *rlc);
void printMAC (struct MAC *mac);
void printUSER(struct USER *user);




int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    // Calculate the total size needed to receive all structs
    size_t total_size = sizeof(nas) + sizeof(rrc) + sizeof(sdap) + sizeof(pdcp) + sizeof(rlc) + sizeof(mac) + sizeof(user);
    char buffer[total_size];
    printf("Buffer size : %ld\n",total_size);

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server address setup
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4000); // Port number
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections...\n");

    // Accept client connections
    socklen_t addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
    if (client_socket == -1) {
        perror("Acceptance failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected\n");

    // Receive the buffer containing all three structs from the client
    recv(client_socket, buffer, total_size, 0);
    printf("Received %ld bytes of data from the client\n",sizeof(buffer));
    
    for(int i=0; i< total_size; i++){
    	printf("Loop %d : Buffer : %d\n",i,buffer[i]);
    }

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
    
    

    
    
	printf("--------------------------------\n");
    	printNAS(&nas);
    	printRRC(&rrc);
    	printSDAP(&sdap);
    	printPDCP(&pdcp);
    	printRLC(&rlc);
    	printMAC(&mac);
    	printUSER(&user);
   
    	close(client_socket);
    	close(server_socket);

    return 0;
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

