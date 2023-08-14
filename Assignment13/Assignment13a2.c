// Write a program which creates child process and parent process will communicate with child process by sending signals.

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void sighup();
void sigint();
void sigquit();

int main()
{
    int pid;
    if((pid = fork()) < 0)
    {
        exit(1);
    }

    if(pid == 0) //child process
    {
        signal(SIGHUP,sighup);
        signal(SIGINT,sigint);
        signal(SIGQUIT,sigquit);
        for(;;);
    }
    else    //parent process
    {
        printf("\nPARENT: sending SIGHUP\n\n");
        kill(pid,SIGHUP);
        sleep(3);

        printf("\nPARENT: sending SIGINT\n\n");
        kill(pid,SIGINT);
        sleep(3);

        printf("\nPARENT: sending SIGQUIT\n\n");
        kill(pid,SIGQUIT);
        sleep(3);
    }
}

void sighup()
{
    signal(SIGHUP,sighup);
    printf("CHILD: I have recieved a SIGHUP\n");
}

void sigint()
{
    signal(SIGINT,sigint);
    printf("CHILD: I have recieved a SIGINT\n");
}

void sigquit()
{
    printf("Parent process kill child\n");
    exit(0);
}












// OUTPUT
// ./Assignment13a2
// PARENT: sending SIGHUP
// CHILD: I have recieved a SIGHUP

// PARENT: sending SIGINT
// CHILD: I have recieved a SIGINT

// PARENT: sending SIGQUIT
// Parent process kill child
