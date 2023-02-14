#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    
    // 创建socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("ERROR opening socket");
        exit(1);
    }
    
    // 初始化socket
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5001;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    // 绑定socket
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
    {
        perror("ERROR on binding");
        exit(1);
    }
    
    // 监听socket
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    // 接受客户端连接
    newsockfd = accept(sockfd, 
                (struct sockaddr *) &cli_addr, 
                &clilen);
    if (newsockfd < 0) 
    {
        perror("ERROR on accept");
        exit(1);
    }
    
    // 读取客户端发送的消息
    bzero(buffer,256);
    n = read(newsockfd,buffer,255);
    if (n < 0) 
    {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Here is the message: %!s(MISSING)\n",buffer);
    
    // 向客户端发送消息
    n = write(newsockfd,"I got your message",18);
    if (n < 0) 
    {
        perror("ERROR writing to socket");
        exit(1);
    }
    
    close(newsockfd);
    close(sockfd);
    return 0; 
}
