// Write a program which creates multiple threads and sets its thread attributes accordingly.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 5

void* threadFunction(void* arg) {
    
    int threadId = *(int*)arg;
    printf("Thread %d is running.\n", threadId);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS];
    int threadIds[THREADS];

    for (int i = 0; i < THREADS; ++i) {
        threadIds[i] = i;
        pthread_attr_t attr;
        pthread_attr_init(&attr);

        if (pthread_create(&threads[i], &attr, threadFunction, &threadIds[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
             return -1;
        }

        pthread_attr_destroy(&attr);
    }

    for (int i = 0; i < THREADS; ++i) {
        if (pthread_join(threads[i], NULL) != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
             return -1;
        }
    }

    return 0;
}
