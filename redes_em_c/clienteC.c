
#define _XOPEN_SOURCE 700 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int arg, char* args[]){

        if (arg < 3) {
                fprintf(stderr, "Uso: %s <IP> <Porta>\n", args[0]);
                exit(1);
        }
        struct sockaddr_in dest;
        int iBytes;
        char buffer[101];
        int iSock = socket(AF_INET, SOCK_STREAM, 0);
        if(iSock == -1){
                perror("Erro no socket:");
                exit(1);
        }
        memset(&dest, 0, sizeof(dest));
        dest.sin_family = AF_INET;
        dest.sin_port = htons(atoi(args[2]));
        dest.sin_addr.s_addr = inet_addr(args[1]);
         
        if(connect(iSock, (struct sockaddr*)&dest, sizeof(dest)) <0){
                perror("Connect: ");
                exit(1);
        }
        if((iBytes=recv(iSock, buffer, 100,0)) < 0){
                perror("Recv: ");
                exit(1);
        }
        buffer[iBytes] = '\0';
        printf("%s",buffer);
        close(iSock);
        return 0;
 }
