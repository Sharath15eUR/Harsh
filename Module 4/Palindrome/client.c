#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }


    bzero(buffer, 1024);
    fgets(buffer, 1024, stdin);
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, 1024);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s\n", buffer);

    close(sockfd);

    return 0;
}