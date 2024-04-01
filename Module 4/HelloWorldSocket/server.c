#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address and port
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(sockfd, 5); // Max 5 connections..
    printf("Server listening on port 8080...\n");

    addr_size = sizeof(client_addr);
    new_socket = accept(sockfd, (struct sockaddr*)&client_addr, &addr_size);
    if (new_socket == -1) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    bzero(buffer, 1024);
    recv(new_socket, buffer, sizeof(buffer), 0);
    printf("Client: %s\n", buffer);

    bzero(buffer, 1024);
    strcpy(buffer, "Hello, client! I'm the server.");
    send(new_socket, buffer, strlen(buffer), 0);

    close(new_socket);
    close(sockfd);

    return 0;
}
