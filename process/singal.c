#include "unistd.h"
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

char buf[2];
int fd;
volatile int loop =0;
void  tim_handle(int s)
{
    read(fd,buf,2);
    write(0,buf,2);
    alarm(1);
    loop = 0;
}

int main(int argc,char *argv[])
{
    fd = open("./miu.log",O_RDWR);
    signal(SIGALRM,tim_handle);
    alarm(1);
    while (!loop)
    {
        pause();
    }
    return 0;
}