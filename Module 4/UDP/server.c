#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXSIZE 1024

int main() {
    char buffer[MAXSIZE];
    char *message = "Hello Client";
    int sockfd, len;
    struct sockaddr_in servaddr, cliaddr;

    bzero(&servaddr, sizeof(servaddr));
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    servaddr.sin_family = AF_INET;

    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    len = sizeof(cliaddr);

    int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&cliaddr, &len);
    buffer[n] = '\0';
    puts(buffer);

    sendto(sockfd, message, MAXSIZE, 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr));
}
