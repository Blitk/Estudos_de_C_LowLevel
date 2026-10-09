#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int arg, char *args []){
        int file = open(args[1], O_WRONLY | O_CREAT, 0744);
        if(file == -1){
                fprintf(stderr, "%s",strerror(errno));
        }
        write(file, "Arquivo criado!\n", 16);
        close(file);
        return  0;
}
