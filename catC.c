#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int arg, char *args[]){
        int file = open(args[1], O_RDONLY);
        if(file == -1){
                printf("%s",strerror(errno));
                return 1;
        }
        char buffer[2000];
        ssize_t bytesBuff = read(file, buffer, sizeof(buffer)-1);
        if(bytesBuff == -1){
                printf("%s", strerror(errno));
                close(file);
                return 2;
        }
        buffer[bytesBuff] = '\0';
        printf("%s", buffer);
        close(file);
        return 0;
}
