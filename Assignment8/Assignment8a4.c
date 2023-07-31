// Write a program which creates two processes as process2 and process3 and our parent process terminates till both the processes terminates.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
    int pid2 = 0, pid3 = 0;
    int status2 = 0, status3 = 0;

    printf("Parent process (PID: %d) is running.\n", getpid());

    pid2 = fork();

    if (pid2 < 0) 
    {
        printf("Fork failed for Process 2.\n");
        return 1;
    } 
    else if (pid2 == 0) 
    {
        execl("./process2", "process2", NULL);
        printf("Exec failed for Process 2.\n");
        return 1;
    }

    pid3 = fork();

    if (pid3 < 0) 
    {
        printf("Fork failed for Process 3.\n");
        return 1;
    } 
    else if (pid3 == 0) 
    {
        execl("./process3", "process3", NULL);
        printf("Exec failed for Process 3.\n");
        return 1;
    }

    wait(&status2);
    wait(&status3);

    printf("Parent process is done.\n");

    return 0;
}


// OUTPUT
// ./Assignment8a4
// Parent process (PID: 12021) is running.
// Process 2 (PID: 12022) is running with Parent PID: 12021
// Process 2 is done.
// Process 3 (PID: 12023) is running with Parent PID: 12021
// Process 3 is done.
// Parent process is done.
