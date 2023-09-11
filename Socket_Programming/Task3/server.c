#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

struct USER {
    int id;
};

struct RRC {
    int salary;
};

struct NAS {
    int bonus;
};

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    // Calculate the total size needed to receive all three structs
    size_t total_size = sizeof(struct USER) + sizeof(struct RRC) + sizeof(struct NAS);
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

    // Extract and print the received structs
    char *ptr = buffer;
    struct USER struct1;
    struct RRC struct2;
    struct NAS struct3;

    memcpy(&struct1, ptr, sizeof(struct1));
    ptr += sizeof(struct1);
    memcpy(&struct2, ptr, sizeof(struct2));
    ptr += sizeof(struct2);
    memcpy(&struct3, ptr, sizeof(struct3));

    printf("Received Struct 1:\n");
    printf("ID: %d\n", struct1.id);

    printf("Received Struct 2:\n");
    printf("Salary: %d\n", struct2.salary);

    printf("Received Struct 3:\n");
    printf("Bonus: %d\n", struct3.bonus);

    close(client_socket);
    close(server_socket);

    return 0;
}
