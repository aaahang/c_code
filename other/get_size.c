#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
static int get_size( const char *fn)
{
    struct stat fns;
    if(stat(fn,&fns)<0)
    {  
        perror("fun is ");
    }
    return fns.st_size;

}
static int get_fp(const char *fn)
{
    struct stat fns;
    if(stat(fn,&fns)<0)
    {  
        perror("fun is ");
    }
    
    return 0;
}
int main(int argc,char **argv) 
{
    if(argc<2){
        exit(1);
    }
    fprintf(stdout,"size is %d\n",get_size(argv[1]));
    exit(0);
}