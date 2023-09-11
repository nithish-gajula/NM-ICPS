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

struct USER user;
struct RRC rrc;
struct NAS nas;
struct SDAP sdap;
struct PDCP pdcp;
struct RLC rlc;
struct MAC mac;

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    // Calculate the total size needed to receive all three structs
    size_t total_size = sizeof(struct USER) + sizeof(struct RRC) + sizeof(struct NAS) + sizeof(struct SDAP) + sizeof(struct PDCP) + sizeof(struct RLC) + sizeof(struct MAC);
    char buffer[total_size];

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Server address setup
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345); // Port number
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

    // Extract and print the received structs
    char *ptr = buffer;
    memcpy(&user, ptr, sizeof(user));
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
    printf("user2 : %d\n", user.user2);
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("Received RRC Header\n");
    printf("rrc1 : %d\n", rrc.rrc1);
    printf("rrc2 : %d\n", rrc.rrc2);
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("Received NAS Header\n");
    printf("nas1 : %d\n", nas.nas1);
    printf("nas2 : %d\n", nas.nas2);
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("Received SDAP Header\n");
    printf("RDI : %d\n", sdap.RDI);
    printf("RQI : %d\n", sdap.RQI);
    printf("QFI : %d\n", sdap.QFI);
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("Received PDCP Header\n");
    printf("DC : %d\n", pdcp.DC);
    printf("R : %d\n", pdcp.R);
    printf("SN : %d\n", pdcp.SN);
    printf("SN1 : %d\n", pdcp.SN1);
    printf("SN2 : %d\n", pdcp.SN2);
    printf("Data : %d\n", pdcp.Data);
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("Received RLC Header\n");
    printf("DC : %d\n", rlc.DC);
    printf("P : %d\n", rlc.P);
    printf("SI : %d\n", rlc.SI);
    printf("SN : %d\n", rlc.SN);
    printf("SO : %d\n", rlc.SO);
    printf("--------------------------------\n");
    printf("--------------------------------\n");
    printf("Received MAC Header\n");
    printf("R : %d\n", mac.R);
    printf("F : %d\n", mac.F);
    printf("LCID : %d\n", mac.LCID);
    printf("L : %d\n", mac.L);
    printf("--------------------------------\n");


    close(client_socket);
    close(server_socket);

    return 0;
}
