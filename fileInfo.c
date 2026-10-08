
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main(int arg, char *args[]){

        if(arg != 2){
                printf("Especifique o arquivo!\n");
                exit(1);
        }

        struct stat fileInfo;

        if(stat(args[1], &fileInfo) < 0){
                printf("Erro ao ler arquivo: %s\n", strerror(errno));
                exit(1);
        }

        printf("Device: %llu\n", (unsigned long long)fileInfo.st_dev);
        printf("Inode: %llu\n", (unsigned long long)fileInfo.st_ino);
        printf("Mode: %o\n", fileInfo.st_mode);
        printf("Hard links: %llu\n", (unsigned long long)fileInfo.st_nlink);
        printf("User ID: %d\n", fileInfo.st_uid);
        printf("Group ID: %d\n", fileInfo.st_gid);
        printf("Size: %llu\n", (unsigned long long)fileInfo.st_size);
        printf("Last acess: %s", ctime(&fileInfo.st_atime)); // ctime já inclui o \n
        printf("Last modif.: %s", ctime(&fileInfo.st_mtime));
        printf("Last st. ch.: %s", ctime(&fileInfo.st_ctime));

        if(S_ISREG (fileInfo.st_mode) ){
                printf("%s --> Common file\n", args[1]);
        }
        if (S_ISDIR (fileInfo.st_mode)){
                printf("%s --> Directory\n", args[1]);
        }
        if (S_ISCHR (fileInfo.st_mode)){
                printf("%s --> Character oriented device\n", args[1]);
        }
        if (S_ISBLK (fileInfo.st_mode)){
                printf("%s --> Block oriented device\n", args[1]);
        }
        if (S_ISFIFO(fileInfo.st_mode)){
                printf("%s --> Pipe file or FIFO\n", args[1]);
        }
        if(S_ISLNK(fileInfo.st_mode)){
                printf("%s --> Symbolic link\n", args[1]);
        }

        printf("\nFile permissions:\n");
        printf("%c", (fileInfo.st_mode & S_IRUSR) ? 'r' : '-');
        printf("%c", (fileInfo.st_mode & S_IWUSR) ? 'w' : '-');
        printf("%c", (fileInfo.st_mode & S_IXUSR) ? 'x' : '-');
        printf(" ");
        printf("%c", (fileInfo.st_mode & S_IRGRP) ? 'r' : '-');
        printf("%c", (fileInfo.st_mode & S_IWGRP) ? 'w' : '-');
        printf("%c", (fileInfo.st_mode & S_IXGRP) ? 'x' : '-');
        printf(" ");
        printf("%c", (fileInfo.st_mode & S_IROTH) ? 'r' : '-');
        printf("%c", (fileInfo.st_mode & S_IWOTH) ? 'w' : '-');
        printf("%c", (fileInfo.st_mode & S_IXOTH) ? 'x' : '-');
        printf("\n");

        return 0;
}
