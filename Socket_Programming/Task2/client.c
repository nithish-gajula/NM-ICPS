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


void updateNAS (struct NAS *nas);
void updateRRC (struct RRC *rrc);
void updateSDAP (struct SDAP *sdap);
void updatePDCP (struct PDCP *pdcp);
void updateRLC (struct RLC *rlc);
void updateMAC (struct MAC *mac);
void updateUSER(struct USER *user);





int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    
    // Create 7 structs
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

    // Calculate the total size needed to send all structs
    size_t total_size = sizeof(nas) + sizeof(rrc) + sizeof(sdap) + sizeof(pdcp) + sizeof(rlc) + sizeof(mac) + sizeof(user);
    char buffer[total_size];
    printf("Buffer size : %ld\n",total_size);

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server address setup
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4000); // Port number on the server
    server_addr.sin_addr.s_addr = inet_addr("192.168.11.188"); // Replace with the server's IP address

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
printf("connected...\n");

    // Copy the structs into the buffer
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
    

    // Send the buffer containing all structs to the server
    send(client_socket, buffer, total_size, 0);
    printf("Sent %ld bytes of data to the server\n",sizeof(buffer));
    
    for(int i=0; i< total_size; i++){
    	printf("Loop %d : Buffer : %d\n",i,buffer[i]);
    }

    close(client_socket);
    printf("Disconnected from the server.\n");
    
    	
    	

    return 0;
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
    user->user1 = 'N';
}


















