#include <stdio.h>  
#include <stdlib.h>
#include <string.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <fcntl.h>  

union 
{
 struct {
    int a,b,c,d;    
 }uc;
 char  uk[15];
}ck;
int  main(int argc, char **argv)
{
    ck.uc.a= 10;
    mkfifo("/tmp/fifo",0777);
   int fd = open("/tmp/fifo",O_WRONLY);
   if(fd < 0)
   {
        perror("open is err");
        exit(1);
   }
   while (1)
   {
       ck.uc.a++;
       write(fd,ck.uk,15);
       sleep(3);
   }
   close(fd);
}