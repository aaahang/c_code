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
    int a, b,c,d;    
 }uc;
 char  uk[15];
}ck;
int  main(int argc, char **argv)
{
   int fd = open("/tmp/fifo",O_RDONLY);
  if(fd < 0)
   {
        perror("open is err");
        exit(1);
   }
   ck.uc.a  =1;
  while (1)
   { 
       read(fd,ck.uk,15);
       printf("a is %d\n",ck.uc.a);
       sleep(2);
   }


}