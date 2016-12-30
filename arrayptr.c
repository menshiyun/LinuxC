#include <stdio.h>

int main(void)
{
    unsigned char a[]={0,1,2,3,4,5,6,7,8,9},*p;
    for(p=a;p<&a[sizeof(a)];p++)
        printf("%d",*p);
    return 0;
}

