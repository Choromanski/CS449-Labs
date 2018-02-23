#include <stdio.h>

#ifdef _REENTRANT
// 1. Include header file with pthread function declarations
#include <pthread.h>
// 2. Define mutex variable for locking (Part 2)
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 
#endif

#define MAX 10000000

int global = 0;

void *foo(void *p) {
  int i;
  int local = 0;
  for(i = 0; i < MAX; i++) {
    if(local % 200 == 0) {
      pthread_mutex_lock(&mutex); 
      global++;
      pthread_mutex_unlock(&mutex);
    }
    local++;
  }
  pthread_mutex_lock(&mutex);
  printf("local=%d, global=%d\n", local, global);
  pthread_mutex_unlock(&mutex);
  return  NULL;
}

int main()
{
#ifdef _REENTRANT
  // 1. Declare two pthread_t variables to store thread IDs
  pthread_t thread1;
  pthread_t thread2;
  // 2. Create two threads using pthread_create() using above variables
  pthread_create(&thread1, NULL, foo, (void*) NULL);
  pthread_create(&thread2, NULL, foo, (void*) NULL);
  // 3. Wait for the two threads to finish before returning using pthread_join()
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
#else
  foo(NULL);
  foo(NULL);
#endif
  return 0;
}
