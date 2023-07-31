// Write a program which create three level process hierarchy where process 1 creates process 2 and it internally creates process 3.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int process3() 
{
    int PID = getpid();
    int PPID = getppid();
    printf("Process 3 (PID: %d) is running. Parent PID: %d\n", PID, PPID);
    printf("Process 3 is done.\n");
    return 0;
}

int process2() 
{
    pid_t pid3;
    int PID = getpid();
    int PPID = getppid();
    printf("Process 2 (PID: %d) is running. Parent PID: %d\n", PID, PPID);

    pid3 = fork();

    if (pid3 < 0) 
    {
        printf("Fork failed for Process 2.\n");
        return 1;
    } else if (pid3 == 0) 
    {
        return process3();
    } 
    else 
    {
        int status;
        waitpid(pid3, &status, 0);
        printf("Process 2 is done.\n");
        return 0;
    }
}

int process1() 
{
    pid_t pid2;
    int PID = getpid();
    printf("Process 1 (PID: %d) is running.\n", PID);

    pid2 = fork();

    if (pid2 < 0) 
    {
        printf("Fork failed for Process 1.\n");
        return 1;
    } 
    else if (pid2 == 0) 
    {
        return process2();
    } 
    else 
    {
        int status;
        waitpid(pid2, &status, 0);
        printf("Process 1 is done.\n");
        return 0;
    }
}

int main() 
{
    int PID = getpid();
    printf("PID of running process is : %d\n", PID);

    int PPID = getppid();
    printf("PID of parent process is : %d\n", PPID);

    process1();

    return 0;
}
