// Write a program which creates two processes.
// Process 1 count number of capital characters from demo.txt file.
// And process 2 count number of captial characters from hello.txt file.
// Both the processes writes its count in count.txt file.
// Process1.c, Process2.c

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
   int ret1 = 0, ret2 = 0;
   int pid1,pid2;
     int status1,status2;

   ret1 = fork();
   if(ret1 == 0)
   {
        execl("./Process1","NULL",NULL);
   }

     wait(&status1);

    ret2 = fork();
   if(ret2 == 0)
   {
        execl("./Process2","NULL",NULL);
   }

     wait(&status2);

    return 0;
}

// OUTPUT
// ./Assignment9a2
// Count Succesfully written in count.txt file.
// Count Succesfully written in count.txt file.