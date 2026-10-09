#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(int arg, char *args[]){

        if(arg < 2){
                fprintf(stderr, "Especifique o arquivo\n");
               exit(1);
        }

        printf("\nPermissions:\n");
        if(access(args[1], R_OK)){
                printf(" - Read\n");
        }
        if(access(args[1], W_OK)){
                printf(" - Write\n");
        }
        if(access(args[1], X_OK)){
                printf(" - Execute\n");
        }
        return 0;
}
