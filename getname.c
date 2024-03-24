#include "stdio.h" 
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "stdlib.h"
#include "signal.h"
void ck(int a)
{
    printf("lls");
}

int main(int argc,char **argv)
{
    signal(SIGINT,ck);
    int fd = open("tmp/out",O_RDWR|O_CREAT);
    int ret = fork();
    for (int i=0; i<10; i++) {
        printf("+++");
        fflush(NULL);
        sleep(1);

    }
    return 0;
}