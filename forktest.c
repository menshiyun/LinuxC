#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;
    uint8_t i=0;
    pid = vfork();
    if(pid==0)
    {
        i++;
        printf("vfork Child process!%d:%d\n",i,pid);
        pid_t vpid;
        vpid = fork();
        if(vpid==0)
        {
            i++;
            printf("vfork-fork child process!%d:%d\n",i,vpid);
        }
        else
        {
            i++;
            printf("vfork-fork parent process!%d:%d\n",i,vpid);
        }
        exit(0);
    }
    else
    if(pid>0)
    {
        i++;
        printf("vfork Parent process!%d:%d\n",i,pid);
        pid_t vpid;
        vpid = fork();
        if(vpid==0)
        {
            i++;
            printf("vfork parent-child process!%d:%d\n",i,vpid);
        }
        else
        {
            i++;
            printf("vfork parent-parent process!%d:%d\n",i,vpid);
        }
    }
    pid = fork();
    if(pid==0)
    {
        i++;
        printf("fork child process!%d:%d\n",i,pid);
    }
    else
    {
        i++;
        printf("fork parent process!%d:%d\n",i,pid);
    }
    return 0;
}

