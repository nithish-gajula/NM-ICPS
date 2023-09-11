#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>


struct USER {
    unsigned char user1 : 4;
    unsigned char user2 : 4;
};

struct RRC {
    unsigned char rrc1 ;
    unsigned char rrc2 ;
};

struct NAS {
    unsigned char nas1: 4;
    unsigned char nas2: 4;
};

struct SDAP {
    unsigned char RDI: 1;
    unsigned char RQI: 1;
    unsigned char QFI: 6;
};

struct PDCP {
    unsigned char DC: 1;
    unsigned char R: 5;
    unsigned char SN: 2;
    unsigned char SN1;
    unsigned char SN2;
    unsigned char Data;
};

struct RLC {
    unsigned char DC: 1;
    unsigned char P: 1;
    unsigned char SI: 2;
    unsigned char SN: 4;
    unsigned char SO;
};

struct MAC {
    unsigned char R: 1;
    unsigned char F: 1;
    unsigned char LCID: 6;
    unsigned char L;
};

void updateUSER(struct USER *user);
void updateRRC (struct RRC *rrc);
void updateNAS (struct NAS *nas);
void updateSDAP (struct SDAP *sdap);
void updatePDCP (struct PDCP *pdcp);
void updateRLC (struct RLC *rlc);
void updateMAC (struct MAC *mac);



int main() {
    int client_socket;
    struct sockaddr_in server_addr;

    // Create three sample structs of different sizes
    

    //struct USER *user = (struct USER*) malloc(sizeof(struct USER));
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

    //printf("user1 : %d\n",user->user1);

    // Calculate the total size needed to send all three structs
    size_t total_size = sizeof(user) + sizeof(rrc) + sizeof(nas) + sizeof(sdap) + sizeof(pdcp) + sizeof(rlc) + sizeof(mac);
    char buffer[total_size];

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server address setup
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345); // Port number on the server
    server_addr.sin_addr.s_addr = inet_addr("10.0.2.15"); // Replace with the server's IP address

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

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

    

    // Send the buffer containing all three structs to the server
    send(client_socket, buffer, total_size, 0);
    printf("Sent %ld bytes of data to the server\n",sizeof(buffer));

    close(client_socket);

    return 0;
}

void updateUSER(struct USER *user){
    user->user1 = 1;
    user->user2 = 2;
}

void updateRRC (struct RRC *rrc){
    rrc->rrc1 = 3;
    rrc->rrc2 = 4;
}

void updateNAS (struct NAS *nas){
    nas->nas1 = 5;
    nas->nas2 = 6;
}

void updateSDAP (struct SDAP *sdap){
    sdap->RDI = 0;
    sdap->RQI = 1;
    sdap->QFI = 15;
}

void updatePDCP (struct PDCP *pdcp){
    pdcp->DC = 0;
    pdcp->R = 15;
    pdcp->SN = 1;
    pdcp->SN1 = 253;
    pdcp->SN2 = 254;
    pdcp->Data = 255;
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
