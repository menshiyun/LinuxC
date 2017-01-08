#include <stdio.h>
#include <unistd.h>
int main(void)
{
    printf("My parent 'pid =%d\n",getppid());
    return 0;
}

