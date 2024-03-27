#include "stdio.h"
#include "stdlib.h"
#include "signal.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <sched.h>
#include <string.h>
#include <unistd.h>

#define     PTH_NUM 4
static  pthread_t pth[PTH_NUM];
pthread_once_t pth_once =PTHREAD_ONCE_INIT; 
pthread_mutex_t pth_mut  = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t pth_cond[4] = {PTHREAD_COND_INITIALIZER,PTHREAD_COND_INITIALIZER,PTHREAD_COND_INITIALIZER,PTHREAD_COND_INITIALIZER};
void  pth_once_usr(void)
{
    printf("this is first \n");
}
void * pth_handle(void *i)
{
    while(1)
    {

        if((getchar() == ('0'+ (int)i)))  //应该是getchar出问题了出让调度器之后以后应该又是一个新的getchar  这么写就不对 完全达不成功 getchar 只有一个设备 使用一个线程使用getchar 读取剩下的线程听这个线程的指挥
        //这么写完不成操作 
        {
            pthread_mutex_lock(&pth_mut);
            printf("this is %d\n",(int)i);  
            pthread_once(&pth_once,pth_once_usr); // 只执行一次(在所有线程之中) 
            pthread_mutex_unlock(&pth_mut);
                  }
        else
        {
            sched_yield(); //让出调度器 （让出调度器 让别的线程运行）
        }

        
    }
    pthread_exit(NULL);
}
int main(int argc,char *argv[])
{
    for(int i=0;i <PTH_NUM ; i++)
    {   
        int err =pthread_create(pth+i,NULL,pth_handle,(void *)i);     
        if (err <0 )
        {
           perror(" pthread_create is error") ;
           exit(1);
        }
    }
    for(int i=0;i <PTH_NUM ; i++)
    {
        pthread_join(pth[i],NULL);
    }
}