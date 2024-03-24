#include "stdio.h"
#include "stdlib.h"
#include "signal.h"
#include <pthread.h>
#include <string.h>

static void * pth_handler(void * arg)
{
    puts("pthread");
    pthread_exit(NULL);
}

int main(int argc,char *argv[])
{
    pthread_t ptid;
    puts("begin");
    int err = pthread_create(&ptid,NULL,pth_handler,NULL);
    if (err <0 )
    {
        printf(stderr,"pthread is err %s",strerror(err));
    }
    puts("end");
    pthread_join(ptid,NULL);
    exit(0);
}