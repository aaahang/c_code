#include "stdio.h"
#include "stdlib.h"
#include <stdio.h>
#include "string.h"


int main(int argc ,char **argv)
{
    char *linebuf;
    size_t n;
    if(argc <2)
    {
        fprintf(stderr,"usage ....\n");
        exit(1);
    }
    FILE *fp = fopen(argv[1],"r");
    if(fp ==  NULL)
    {
        perror("fopen()");
        exit(1);
    }
    while(1)
    {
       if( getline(&linebuf,&n,fp)<0)
        break;
        printf("%d\n",strlen(linebuf));

    }
}