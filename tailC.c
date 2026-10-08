#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int main(int arg, char *args[]){
        int file = open(args[1], O_RDONLY);
        if(file == -1){
                printf("%s", strerror(errno));
                return 1;
        }
        off_t tam = lseek(file, 0, SEEK_END);
        lseek(file, tam - 500, SEEK_SET);
        char buffer[501];
        ssize_t bytesBuff = read(file, buffer, 500);
        if(bytesBuff <= 0){
                printf("%s", strerror(errno));
                return 2;
        }
        buffer[bytesBuff] = '\0';
        printf("%s", buffer);
        close(file);
        return 0;


}
