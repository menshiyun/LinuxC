#include <stdio.h>
#include <stdarg.h> 
void simple_va_fun(int start,...)
{
    va_list arg_ptr;
    int nArgValue = start;
    int nArgCout=0;
    va_start(arg_ptr,start);
    do
    {
        ++nArgCout;
        printf("the %d th arg: %d\n",nArgCout,nArgValue);
        nArgValue=va_arg(arg_ptr,int);
    }while(nArgValue!=-1);
    return;
}
int main(int argc,char *argv[])
{
    simple_va_fun(100,-1);
    simple_va_fun(100,200,-1);
    return 0;
}
