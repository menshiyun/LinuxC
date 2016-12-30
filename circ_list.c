#include <stdio.h>

typedef struct circ_list
{
    char value[3];
    struct circ_list * next;
}circ_list_node;

circ_list_node suffixes[] = {
    "00", &suffixes[1],
    "11", &suffixes[2],
    "22", &suffixes[3],
    "33", &suffixes[4],
    "44", &suffixes[5],
    "55", &suffixes[6],
    "66", &suffixes[7],
    "77", &suffixes[8],
    "88", &suffixes[9],
    "99", &suffixes[0],
};

#define MAX 20

int main(void)
{
    int i=0;
    circ_list_node *p = suffixes;
    while(i<=MAX)
    {
        printf("%d.%s\n",i,p->value);
        i++;
        p=p->next;
    }
    return 0;
}

