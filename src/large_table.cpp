#include "large_table.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>

// Function to read the cycle counter on ARM CPUs
static inline uint64_t rdtsc(void) {
  uint64_t value;
  // Read the cycle counter
  asm volatile("mrs %0, cntvct_el0" : "=r"(value));
  return value;
}

pthread_barrier_t barrier;

void *thread_function(void *arg) {
  uint64_t start, end;

  // Wait for all threads to reach this point
  pthread_barrier_wait(&barrier);

  start = rdtsc();
  // Simulate some work with a loop
  for (int i = 0; i < 1000000; ++i)
    ;

  end = rdtsc();

  printf("Thread %ld - Start TSC: %lu\n", (long)arg, start);
  printf("Thread %ld - End TSC: %lu\n", (long)arg, end);
  printf("Thread %ld - Elapsed TSC: %lu\n", (long)arg, end - start);

  return NULL;
}

void large_table() {
  pthread_t threads[3];

  // Initialize the barrier for 3 threads
  pthread_barrier_init(&barrier, NULL, 3);

  for (long i = 0; i < 3; ++i) {
    pthread_create(&threads[i], NULL, thread_function, (void *)i);
  }

  for (int i = 0; i < 3; ++i) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the barrier
  pthread_barrier_destroy(&barrier);
}