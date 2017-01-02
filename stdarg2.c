#include <stdio.h>
#include <string.h>
#include <stdarg.h> 

char *multiConcat(char *result, int numArgs, ...)
{
    strcpy (result,"");

    va_list args;
    va_start(args,numArgs);

    for(int i=0;i<numArgs;i++)
    {
        char *str = va_arg(args,char*);
        strcat(result,str);
    }

    va_end(args);
    return result;
}

int main(void)
{
    char result[200+1],str[]="This is a test";

    multiConcat(result,3,"string1","string2","string3");
    printf("The result is %s\n",result);
    printf("The strings all concatenated together art:%s\n",
            multiConcat(result,5,"A",str,"123","*result","XXX"));
    return 0;
}
