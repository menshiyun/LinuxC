#include <stdio.h>
int cal(int n)
{
    if(n==1)
        return 1;
    else
        return n*cal(n-1);
}

int main(void)
{
    int n=5;
    n=cal(n);
    printf("%d\n",n);
    return 0;
}
