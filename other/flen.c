#include "stdio.h"
#include "stdlib.h"
#include <stdio.h>
/*

*/
int main(int argc ,char **argv)
{
    FILE *fp = fopen("mmd","r+");
    if (fp == NULL)
    {
        perror("fopen is error");
        exit(1);
    }
    fflush(stdout); //刷新缓冲区
    fseek(fp,0,SEEK_END); //移动文件的标
    long len = ftell(fp); //返回文件标
    printf("len is %ld\n",len);
    rewind(fp); //返回到最开始
    len = ftell(fp);  
    printf("len is %ld\n",len);
    exit(0);
}