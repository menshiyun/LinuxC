#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *myThread1(void)
{
  int i;
  for (i = 0; i < 100; i++) {
    printf("This is the 1st pthread, created by zieckey.\n");
    sleep(1);
  }
}

void *myThread2(void)
{
  int i;
  for (i = 0; i < 100; i++) {
    printf("This is the 2st pthread, created by zieckey.\n");
    sleep(1);
  }
}

int main(void)
{
  int i=0, ret=0;
  pthread_t id1,id2;

  ret = pthread_create(&id1,NULL,(void*)myThread1,NULL);
  if(ret)
  {
    printf("Create pthread error!\n");
    return 1;
  }

  ret = pthread_create(&id2,NULL,(void*)myThread2,NULL);
  if(ret)
  {
    printf("Create pthread error!\n");
    return 1;
  }

  pthread_join(id1,NULL);
  pthread_join(id2,NULL);

  return 0;
}
