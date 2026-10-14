
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int arg, char *args[]){

        if(arg != 3){
                printf("\nUso: %s <PORTA> <N HOSTs>\n", args[0]);
                exit(1);
        }

        int iSock;
        struct sockaddr_in my_addr;

        iSock = socket(AF_INET, SOCK_STREAM,0);
        if(iSock == -1){
                perror("Socket error: ");
                exit(1);
        }

        memset(&my_addr, 0, sizeof(my_addr));
        my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(atoi(args[1]));
        my_addr.sin_addr.s_addr = INADDR_ANY;

        if(bind(iSock, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1){
                perror("Bind error :");
                exit(1);
        }

        if(listen(iSock, atoi(args[2])) <0)){
                perror("Listen error: ");
                exit(1);
        }


        while(1){
                int iFd;
                struct sockaddr_in client_addr;
                socklen_t sin_size;
                char szMensagem[101];
                sin_size = sizeof(struct sockaddr_in);
                if((iFd = accept(iSock, (struct sockaddr*) &client_addr, &sin_size)) < 0){

                        perror("Accept error: ");
                        exit(1);
                }
                printf("\n[+] - Conexao recebida de %s\n", inet_ntoa(client_addr.sin_addr));
                memset(szMensagem, 0, sizeof(szMensagem));
                strcpy(szMensagem, "Conexao bem sucedida!\n");
                if(send(iFd, szMensagem, strlen(szMensagem), 0) < 0){
                        perror("Send error: ");
                        exit(1);
                }
                close(iFd);
        }

        close(iSock);
        return 0;
}
