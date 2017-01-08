#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
    int a=5;
    int b=2;
    pid_t pid;
    pid = fork();
    if(pid==0)
    {
        a=a-4;
        printf("I'm a child process with PID [%d],the value of a: %d, the value of b:%d.\n",pid,a,b);
    }
    else if(pid<0)
    {
        perror("fork");
    }
    else
    {
        printf("I'm a parent process, with PID [%d],the value of a: %d, the value of b:%d.\n",pid,a,b);
    }
    return 0;
}
