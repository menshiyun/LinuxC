
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define THREAD_MAX 3
#define LOOP 3

int number = 0;
// pthread_mutex_t mutex;
// pthread_cond_t cond;
sem_t sem[THREAD_MAX];

void *thread(void *arg) {
  int num = (int)arg;
  int no = num == THREAD_MAX - 1 ? 0 : num + 1;
  for (int i = 0; i < LOOP; i++) {
    // pthread_mutex_lock(&mutex);
    // pthread_cond_wait(&cond, &mutex);
    sem_wait(&sem[num]);
    number++;
    printf("thread:%d number:%d tid:%u\n", num + 1, number,
           (unsigned int)pthread_self());
    sleep(1);
    sem_post(&sem[no]);
    // pthread_cond_signal(&cond);
    // pthread_mutex_unlock(&mutex);
  }
}

int main(int argc, char const *argv[]) {
  pthread_t td[THREAD_MAX];
  // pthread_mutex_init(&mutex, NULL);
  // pthread_cond_init(&cond, NULL);
  for (int i = 0; i < THREAD_MAX; i++) {
    sem_init(&sem[i], 0, 0);
    pthread_create(&td[i], NULL, thread, (void *)i);
  }
  sem_post(&sem[0]);
  // pthread_cond_signal(&cond);
  for (int i = 0; i < THREAD_MAX; i++) {
    pthread_join(td[i], NULL);
  }
  for (int i = 0; i < THREAD_MAX; i++) {
    sem_destroy(&sem[i]);
  }
  // pthread_mutex_destroy(&mutex);
  // pthread_cond_destroy(&cond);
  return 0;
}
