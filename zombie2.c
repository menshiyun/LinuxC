#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
    if(!fork())
    {
        printf("child pid=%d\n",getpid());
        exit(0);
    }
    sleep(60);
    printf("parent pid=%d\n",getpid());
    exit(0);
    return 0;
}
