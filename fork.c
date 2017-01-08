#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t child;
    int status;

    printf("This will demostrate how to get child status\n");

    if((child=fork())==-1)
    {
        printf("Fork Error : %s\n",strerror(errno));
        exit(1);
    }
    else if(child==0)
    {
        int i;
        printf("I am the child: %d\n", getpid());
        for(i=0;i<1000000;i++)sin(i);
        i=5;
        printf("I exit with %d\n",i);
        exit(i);
    }
    return 0;
}

