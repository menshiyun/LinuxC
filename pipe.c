#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int filedes[2];
    char buffer[80];
    pipe(filedes);//建立无名管道int pipe(int filedes[2]);
    if(fork()>0)
    {
        char s[]="hello\n";
        write(filedes[1],s,sizeof(s));//管道的元素1为写入端
    }
    else
    {
        read(filedes[0],buffer,80);//管道的元素0为读取端
        printf("%s",buffer);
    }
    return 0;
}

