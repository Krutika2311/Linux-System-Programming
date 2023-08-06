// Write a program which creates new process which is responsible to write all file names which are present on desktop in demo file which should be created newly. 
//Refer Process.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int ret1 = 0;
    int pid1;
    int status1;

    ret1 = fork();
    if (ret1 == 0)
    {
        execl("./Process", "./Process", NULL);
    }

    wait(&status1);
    printf("Process have finished.\n");

    return 0;
}


// ./Assignment9a1
// File names on the desktop written to demo.txt by the process.
// Process have finished.
