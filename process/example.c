#include "stdio.h"
#include "stdlib.h"
#include <signal.h>
struct  sigaction sig;
int main(int argc ,char *argvp[])
{
    sigaction();
    exit(0); // 调用前会调用atexit所钩住的函数
}