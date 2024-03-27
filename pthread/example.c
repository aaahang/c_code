#include "stdio.h"
#include "stdlib.h"
#include "signal.h"
#include <pthread.h>
#include <string.h>
#include <unistd.h>
pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t  mutex1 = PTHREAD_MUTEX_INITIALIZER;
void *pt_handle(void *pt_arg)
{
    int sec_p = (int)pt_arg;
    for (int  i = (sec_p*60); i < (sec_p*60+60); i++)
    {

        for (int j=2;j<i;j++)
        {
            if((i % j) == 0 && i != j)
                {
                    break;
                }
            if (j == i-1)
                {
                    // pthread_mutex_lock(&mutex1);
                    printf("sec_p is %d  素数 is %d\n",sec_p,i);
                    // pthread_mutex_unlock(&mutex1);
                }
        }
    }
    pthread_exit(NULL);
}
int main(int argc,char *argv[])
{
    // printf("code is begin\n");
    pthread_t tid[1024];
    for( int i = 0;i< 500;i++)
    {
       int err=   pthread_create(&tid[i],NULL,pt_handle,(void *)i); //启动不了和i有关 很多个线程一起操作i（地址）
       if (err < 0 )
       {
        perror("pthread is erro");
    }
    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&mutex1);
    for(int i = 0;i< 500;i++)
    {
    pthread_join(tid[i],NULL);
    }
    exit(0);
}

