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
    int client_socket;
    struct sockaddr_in server_addr;

    // Create three sample structs of different sizes
    struct USER struct1 = {1};
    struct RRC struct2 = {2};
    struct NAS struct3 = {3};

    // Calculate the total size needed to send all three structs
    size_t total_size = sizeof(struct1) + sizeof(struct2) + sizeof(struct3);
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
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with the server's IP address

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Copy the structs into the buffer
    char *ptr = buffer;
    memcpy(ptr, &struct1, sizeof(struct1));
    ptr += sizeof(struct1);
    memcpy(ptr, &struct2, sizeof(struct2));
    ptr += sizeof(struct2);
    memcpy(ptr, &struct3, sizeof(struct3));

    // Send the buffer containing all three structs to the server
    send(client_socket, buffer, total_size, 0);
    printf("Sent all three structs to the server\n");

    close(client_socket);

    return 0;
}
