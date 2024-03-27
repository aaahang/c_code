#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFSIZE 1024


{
    int fd1=0,fd2=0;
    if(argc <3)
    {
        fprintf(stderr,"usage .. ..\n"); //在stderr中立即打印不存放在缓冲区
        exit(1);
    }
    fd1 = open(argv[1],O_RDONLY);
    if (fd1 <0) {
        perror("open()");
        exit(1);
    }
    fd2 = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0600); //0600 为给创建的文件的权限
    if (fd2 <0) {
        close(fd1); //防止内存泄露 fd1没有被清除
        perror("open()");
        exit(1);
    }
    char buf[BUFSIZE];
    int len=0,ret=0;
    while (1)
    {
        len = read(fd1,buf,BUFSIZE);
        if(len<0){
            perror("read error");
            break;
        }
        if (len == 0) {
            break;
        }
        ret = write(fd2,buf,len);
        if (len - ret) {
        
        }
        if(ret<0){
            perror("write");
            break;
        }
    }
    close(fd1);
    close(fd2);
    exit(0);
}