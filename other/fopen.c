#include "stdio.h"
#include "stdlib.h"
#include "errno.h"
#include <cwchar>
int main(int argc,char **argv)
{
    FILE *fp = NULL;
    fp = fopen("mc","r");
    if(fp == NULL)
    { 
        perror("fopen");
        exit(1);
    } 
    
    fclose(fp);
    exit(0);
}