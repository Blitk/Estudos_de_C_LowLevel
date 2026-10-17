
#include <stdlib.h>
#include <stdio.h>

#define DECLARE_MODULE(name) \
       void name##_init(void);\
        void name##_run(void);\
        void name##_destroy(void);

#define IMPLEMENT_MODULE(name, description)\
        void name##_init(void){\
                printf("[" #name "] initiating\n");\
        }\
        void name##_run(void){\
                printf("[" #name "] %s\n", description);\
        }\
        void name##_destroy(void){\
                printf("[" #name "] finishing...\n");\
        }

DECLARE_MODULE(network);
DECLARE_MODULE(memory);
DECLARE_MODULE(disk);

IMPLEMENT_MODULE(network, "monitoring conections");
IMPLEMENT_MODULE(memory, "verifying memory");
IMPLEMENT_MODULE(disk, "verifying disk storage");

int main(){
        printf("\n");

        disk_init();
        memory_init();
        network_init();

        printf("\n");

        disk_run();
        memory_run();
        network_run();

        printf("\n");

        disk_destroy();
        memory_destroy();
        network_destroy();

        printf("\n");

        return 0;

}
