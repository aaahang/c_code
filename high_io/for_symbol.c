#include "stdio.h"
#include "stdlib.h"
#include "for_symbol.h"

struct fsm fs = {
     .fds = 10, 
     .fdd = 11,
    .state_driver = kc
};
int main(int argc,char *argv[])
{
    fs.state_driver(&fs,10,20);

    exit(0);
}

int kc(struct fsm * that,int a,int b)
{
    printf("result is %d",a+b+that->fds);
    switch (that->state)
    {
    case start:
        printf("now  is strat\n");
        that->state = wait;
        break;
    case wait:
        printf("now is wait\n");
        break;
    default :
        break;
    }

    return a+b+that->fds;

}