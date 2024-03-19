#include "stdio.h"
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>


struct passwd * pa;
int main(int argc, char ** argv)
{
    pa = getpwuid(1000);
    puts(pa->pw_name);
    exit(0);                                                                                        
}