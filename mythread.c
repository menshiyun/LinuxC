
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define THREAD_MAX 3
#define LOOP 3

uint8_t number = 0;
// pthread_mutex_t mutex;
// pthread_cond_t cond;
sem_t sem[THREAD_MAX];

void *thread(void *arg) {
  int num = (int)arg;
  for (uint8_t i = 0; i < LOOP; i++) {
    // pthread_mutex_lock(&mutex);
    // pthread_cond_wait(&cond, &mutex);
    sem_wait(&sem[num]);
    number++;
    printf("thread:%d number:%d tid:%u\n", num + 1, number,
           (unsigned int)pthread_self());
    // sleep(1);
    if (num == THREAD_MAX - 1) {
      putchar('\n');
      sem_post(&sem[0]);
    } else
      sem_post(&sem[num + 1]);
    // pthread_cond_signal(&cond);
    // pthread_mutex_unlock(&mutex);
  }
}

int main(int argc, char const *argv[]) {
  pthread_t td[THREAD_MAX];
  // pthread_mutex_init(&mutex, NULL);
  // pthread_cond_init(&cond, NULL);
  for (uint8_t i = 0; i < THREAD_MAX; i++) {
    sem_init(&sem[i], 0, 0);
    pthread_create(&td[i], NULL, thread, (void *)i);
  }
  sem_post(&sem[0]);
  // pthread_cond_signal(&cond);
  for (uint8_t i = 0; i < THREAD_MAX; i++) {
    pthread_join(td[i], NULL);
  }
  for (uint8_t i = 0; i < THREAD_MAX; i++) {
    sem_destroy(&sem[i]);
  }
  // pthread_mutex_destroy(&mutex);
  // pthread_cond_destroy(&cond);
  return 0;
}
