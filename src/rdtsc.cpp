#include "rdtsc.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Function to read the cycle counter on ARM CPUs
static inline uint64_t rdtsc(void) {
  uint64_t value;


#if defined(__aarch64__)
  // ARM64: Read from cntvct_el0 (requires user-mode access to be enabled)
  asm volatile("mrs %0, cntvct_el0" : "=r"(value));
#elif defined(__x86_64__)
  // x86_64: Use rdtsc instruction
  unsigned int lo, hi;
  asm volatile("rdtsc" : "=a"(lo), "=d"(hi));
  value = ((uint64_t)hi << 32) | lo;
#else
  fprintf(stderr, "rdtsc() not supported on this architecture.\n");
  abort();  // crash the program
#endif

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

void run_rdtsc() {
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
