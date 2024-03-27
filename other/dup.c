#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#define  FNAME "./tmp/out"
int main(int argc,char **argv)
{
    int fd;
    close(1);
    fd = open(FNAME,O_RDWR|O_CREAT|O_TRUNC,0777);
    exit(0);
    
}