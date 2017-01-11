#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO "/tmp/2"

int main(void)
{
    char buffer[80];
    int fd;
    unlink(FIFO);
    mkfifo(FIFO,0666);

    if(fork()>0)
    {
        char s[] = "HelloWorld!\n";
        fd = open(FIFO,O_WRONLY);
        write(fd,s,sizeof(s));
        close(fd);
    }
    else
    {
        fd = open(FIFO,O_RDONLY);
        read(fd,buffer,80);
        printf("%s",buffer);
        close(fd);
    }
    return 0;
}

