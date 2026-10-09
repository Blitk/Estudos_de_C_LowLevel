
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("Erro no fork");
        return 1;
    }

    char buff[50];

    if (pid == 0) {
        printf("\n$~: ");
        fflush(stdout);

        if (fgets(buff, sizeof(buff), stdin) == NULL) {
            if (ferror(stdin)) {
                perror("Erro ao ler comando");
                return 1;
            }
            return 0;
        }

        buff[strcspn(buff, "\n")] = '\0';

        execl("/bin/sh", "sh", "-c", buff, (char *)NULL);

        perror("Erro no execl");
        return 1;
    } else {
        if (waitpid(pid, &status, 0) == -1) {
            perror("Erro no waitpid");
            return 1;
        }

        printf("\n");
    }

    return 0;
}

