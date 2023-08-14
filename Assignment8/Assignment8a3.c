// Write a program which creates three different processes internally as process2, process3, process4.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{    
    int pid2 = 0, pid3 = 0, pid4 = 0;
    int status = 0;
    printf("Process 1 (PID: %d) is running.\n", getpid());

    pid2 = fork();

    if (pid2 < 0) 
    {
        printf("Fork failed for Process 1.\n");
        return 1;
    } else if (pid2 == 0) 
    {
        execl("./process2", "process2", NULL);
        printf("Exec failed for Process 2.\n");
        return 1;
    } 
    else 
    {
        waitpid(pid2, &status, 0); 
    }

    pid3 = fork();

    if (pid3 < 0) 
    {
        printf("Fork failed for Process 1.\n");
        return 1;
    } 
    else if (pid3 == 0) 
    {
        execl("./process3", "process3", NULL);
        printf("Exec failed for Process 3.\n");
        return 1;
    } 
    else 
    {
        waitpid(pid3, &status, 0);
    }

    pid4 = fork();

    if (pid4 < 0) 
    {
        printf("Fork failed for Process 1.\n");
        return 1;
    } 
    else if (pid4 == 0) 
    {
        execl("./process4", "process4", NULL);
        printf("Exec failed for Process 4.\n");
        return 1;
    } 
    else 
    {
        waitpid(pid4, &status, 0);
    }

    printf("Process 1 is done.\n");

    return 0;
}


// OUTPUT
// ./Assignment8a3
// Process 1 (PID: 11870) is running.
// Process 2 (PID: 11871) is running with Parent PID: 11870
// Process 2 is done.
// Process 3 (PID: 11872) is running with Parent PID: 11870
// Process 3 is done.
// Process 4 (PID: 11873) is running with Parent PID: 11870
// Process 4 is done.
// Process 1 is done.
