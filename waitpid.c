#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void die(const char *msg)
{
    perror(msg);
    exit(1);
}

void child2_do(void)
{
    printf("In child2: execute'date'\n");
    sleep(5);
    if(execlp("date","date",NULL)<0)
    {
        perror("child2 execlp");
    }
}

void child1_do(pid_t child2, char *argv)
{
    pid_t pw;
    do
    {
        if(*argv=='1')
        {
            pw = waitpid(child2,NULL,0);
        }
        else
        {
            pw = waitpid(child2,NULL,WNOHANG);
        }
        if(pw==0)
        {
            printf("In child1 process:\nThe child2 process has not exited!\n");
            sleep(1);
        }
    }while(pw==0);
    if(pw==child2)
    {
        printf("Get child2 %d.\n",pw);
        sleep(5);
        if(execlp("pwd","pwd",NULL)<0)
        {
            perror("child1 execlp");
        }
    }
    else
    {
        printf("error occured!\n");
    }
}

void father_do(pid_t child1, char *argv)
{
    pid_t pw;
    do
    {
        if(*argv=='1')
        {
            pw = waitpid(child1,NULL,0);
        }
        else
        {
            pw = waitpid(child1,NULL,WNOHANG);
        }
        if(pw==0)
        {
            printf("In father process:\nThe child1 process has no exited!\n");
            sleep(1);
        }
    }while(pw==0);

    if(pw==child1)
    {
        printf("Get child1 %d.\n",pw);
        sleep(5);
        if (execlp("ls","ls","-1",NULL)<0)
        {
            perror("father execlp");
        }
    }
    else
    {
        printf("error occured!\n");
    }
}

int main(int argc, char *argv[])
{
    pid_t child1,child2;
    if(argc<3)
    {
        printf("Usage:waitpid [0 1][0 1]\n");
        exit(1);
    }

    child1=fork();//前面看了后面就忘了，我得查下fork()有几个返回值。
                  //查到了，在父进程中，fork()返回的是子进程的PID，而在子进程中，这个返回值变为0.
    if(child1<0)
    {
        die("child1 fork");
    }
    else if (child1==0) //子进程会运行到这里
    {
        child2=fork();
        if(child2<0)
        {
            die("child2 fork");
        }
        else if(child2==0)
        {
            child2_do();
        }
        else
        {
            child1_do(child2,argv[1]);
        }
    }
    else
    {
        father_do(child1,argv[2]);//把程序运行第二个参数传给father_do
    }
    return 0; //这个就是进程等待的大概意思了吧。就这样了。
}

