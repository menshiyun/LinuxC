#include <stdio.h>
#include <stdarg.h>

int addup(int numArgs, ...)
{
    int sum=0;

    va_list args;
    va_start(args,numArgs);

    for(int i=0;i<numArgs;i++)
    {
        int num = va_arg(args,int);
        sum+=num;
    }
    
    va_end(args);
    return sum;
}

int main(void)
{
    printf("The sum is %d\n",addup(5,1,2,3,4,5));

    int total = addup(8,10,2,-16,47,12,-2,99,7);
    printf("The result is %d\n",total);

    return 0;
}
