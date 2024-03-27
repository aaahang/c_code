#include "stdio.h"
#include "stdlib.h"
#include "signal.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define     PTH_NUM 4
pthread_mutex_t  pth_mutex  =  PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t   pth_cond[4];
static int num =0 ;
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

    while (1){
            pthread_cond_wait(pth_cond+i,&pth_mutex); //内部会对pth_mutex 先解锁在加锁
            fprintf(stdout,"%c",c);
            pthread_cond_signal(pth_cond+next(i));
    }
    pthread_exit(NULL);
}
static  pthread_t pth[PTH_NUM];
void  sa_handle(int s, siginfo_t *info, void *ucontext)
{
    exit(0);
}
void exit_at()
{
    pthread_mutex_destroy(&pth_mutex);
    pthread_cond_destroy(&pth_cond);
}
int main(int argc,char *argv[])
{
    struct sigaction sa = {
        .sa_sigaction =  sa_handle,
        .sa_flags = SA_SIGINFO,
        .sa_mask = NULL
    };
    sigaction(SIGALRM,&sa,NULL);

    for(int i=0;i <PTH_NUM ; i++)
    {   
        pthread_cond_init(pth_cond+i,NULL);
        int err =pthread_create(pth+i,NULL,pth_handle,(void *)i);     
        if (err <0 )
        {
           perror(" pthread_create is error") ;
           exit(1);
        }
    }
    pthread_cond_signal(pth_cond);
    atexit(exit_at);
    alarm(5);
    for(int i=0;i <PTH_NUM ; i++)
    {
        pthread_join(pth[i],NULL);
    }
    
    // 
}