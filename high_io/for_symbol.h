#ifndef FOR_SYMBOL
#define FOR_SYMBOL
struct fsm {
    int fds;
    int fdd;
    int (*state_driver)(struct fsm * that,int a, int b);
    enum {start,wait,work,end}state;
};
int kc(struct fsm * that,int a,int b);

#endif // !FOR_SYMBOL
