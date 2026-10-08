#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int main(int arg, char *args[]){
        int file = open(args[1], O_RDONLY);
        if(file == -1){
                printf("%s",strerror(errno));
                return 1;
        }

        struct stat file_info;
        if(fstat(file, &file_info) == -1){
                printf("%s", strerror(errno));
                close(file);
                return 2;
        }
        size_t fileSize = file_info.st_size;

        char *buffer = malloc(fileSize +1);
        if(buffer == NULL){
                printf("\nErro na alocação da memoria");
                close(file);
                return 3;
        }

        ssize_t bytesBuff = read(file, buffer, fileSize);
        if(bytesBuff == -1){
                printf("%s", strerror(errno));
                free(buffer);
                close(file);
                return 2;
        }
        buffer[bytesBuff] = '\0';
        printf("%s\n", buffer);
        close(file);
        free(buffer);
        return 0;
}
