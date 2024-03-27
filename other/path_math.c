#include "stdio.h"
#include "stdlib.h"
#include <glob.h>
#include "errno.h"
#include <string.h>
static int errfunc1(const char * path_err, int errno)
{
    fprintf(stderr,path_err);
    fprintf(stderr, "err is %s",strerror(errno));
    return 0;
}
int main(int argc,char ** argv)
{
    glob_t glob_1;
    int err =glob("./*",0,NULL,&glob_1);
    if(err)
    {
        exit(1);
    }  
    for (int i =0 ;i<glob_1.gl_pathc;i++)
    printf(glob_1.gl_pathv[i]);
    printf("num is %d",glob_1.gl_pathc);
    exit(0);
    
}