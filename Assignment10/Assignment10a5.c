// Write a program which is used to get thread id inside its thread function.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* ThreadProc(void* ptr)
{
    int threadID = (int)ptr;
    printf("Inside thread with ID: %d\n", threadID);
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID;
    int ret = 0;

    ret = pthread_create(&TID, NULL, ThreadProc, (void*)&TID);
    if (ret != 0)
    {
        printf("Unable to create thread 1\n");
        return -1;
    }
    printf("Thread is created with ID: %ld\n", TID);

    pthread_join(TID, NULL);

    printf("End of main thread\n");

    pthread_exit(NULL);
    return 0;
}
