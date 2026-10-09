#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/utsname.h>

int main(int arg, char *args[]){

        struct utsname infos;

        if(uname(&infos) < 0){
                perror("");
                exit(errno);
        }
        printf("\nSystem name: %s\n", infos.sysname);
        printf("Node name: %s\n", infos.nodename);
        printf("OS release: %s\n", infos.release);
        printf("OS version: %s\n", infos.version);
        printf("Hardware type: %s\n", infos.machine);
        return 0;
}
