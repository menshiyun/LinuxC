#include <stdio.h>

int main(void)
{
    unsigned char a[]={0,1,2,3,4,5,6,7,8,9},i;
    for(i=0;i<sizeof(a);i++)
        printf("%d",a[i]);
    return 0;
}

