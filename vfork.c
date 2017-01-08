#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
    if(vfork()==0)
    {
        printf("This is the child process\n");
        exit(0);
    }else{
        printf("This is the parent process\n");
    }
    return 0;
}
