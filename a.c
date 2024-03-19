#include "stdio.h"
#include "time.h"
#include <bits/getopt_core.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
extern char *optarg;
int main(int argc,char *argv[])
{
    time_t* t1;
    struct  tm *tm1;
    int opt;
    int fd1;
    int fd = open("./tmp/uc",O_RDWR|O_TRUNC|O_CREAT);
    printf("aaaa");
    time(t1);
    while ((opt = getopt(argc,argv,"w:j:t")) != -1)
    {
        switch (opt) {
            case 'w':
                fd1  = open(optarg,O_RDWR|O_CREAT);5
                write(fd1,"cdf",3);
            case 't':
                
        }
    }

    tm1 = localtime(t1);
    printf("%d",tm1->tm_isdst);
    close(fd);
    return 0;
} 