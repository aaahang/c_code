#include "stdio.h"
#include "stdlib.h"
#include "signal.h"
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define     PTH_NUM 4
pthread_mutex_t  pth_mutex [PTH_NUM];

int next(int i)
{
    if(i == PTH_NUM-1)
    {
        return 0;
    }
    return i+1;
}
void * pth_handle(void *arg)
{
    int i  = (int)arg;
    char c  = 'a' + i;

    while (1) {
    pthread_mutex_lock(pth_mutex + i);
       fprintf(stdout,"%c",c);
           pthread_mutex_unlock(pth_mutex + next(i));
    }

    pthread_exit(NULL);
}

int main(int argc,char *argv[])
{
    pthread_t pth[PTH_NUM];
    for(int i=0;i <PTH_NUM ; i++)
    {
        pthread_mutex_init(pth_mutex+i,NULL);
        int err =pthread_create(pth+i,NULL,pth_handle,(void *)i);     
        pthread_mutex_lock(pth_mutex + i);
        if (err <0 )
        {
           perror(" pthread_create is error") ;
           exit(1);
        }
    }
    pthread_mutex_unlock(pth_mutex);
    alarm(5);
    
    for(int i=0;i <PTH_NUM ; i++)
    {
        pthread_join(pth[i],NULL);
        pthread_mutex_destroy(pth_mutex+i);
    }
}