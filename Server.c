#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main() {
    printf("This is server!!\n");
    int sockfd, bfd;
    struct sockaddr_in my_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == -1) {
        printf("Socket error\n");
    } else {
        my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(1050);
        my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        bfd = bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));

        if (bfd == -1) {
            printf("Bind fail\n");
        } else {
            printf("Bind Success\n");
        }
    }

    return 0;
}

