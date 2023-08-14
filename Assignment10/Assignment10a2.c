// Write a program which creates two thread, first thread print numbers from 1 to 500 & other thread print the numbers from main thread.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

// void * _____ (void * ___)
// {}

void * ThreadProc(void *ptr)
{
  int i = 0;

  for(i = 1; i <= 500; i++)
  {
    printf("Thread with counter : %d\n",i);
  }
  pthread_exit(NULL);
}

void* ThreadProcMain(void* ptr)
{
    int i;
    for (i = 501; i <= 1000; i++)
    {
        printf("Main Thread with counter: %d\n", i);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1, TID2;
    int ret1 = 0, ret2 = 0;

    ret1 = pthread_create(&TID1,        // Address of pthread_attr_t structure object
                          NULL,       // Thread attributes
                          ThreadProc, // Address of callback function
                          NULL);      // Parameters to callback function

    if(ret1 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
     ret2 = pthread_create(&TID2, NULL, ThreadProcMain, NULL);
    if (ret2 != 0)
    {
        printf("Unable to create thread 2\n");
        return -1;
    }

    printf("Thread1 is created with ID : %d\n",TID1);
      printf("Thread2 is created with ID : %d\n",TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    

    printf("End of main thread\n");
    
    pthread_exit(NULL);
    return 0;
}