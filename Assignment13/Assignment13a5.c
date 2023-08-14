// Write a program which creates two process as sender and receiver in which sender process send signal to receiver process.

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void receiver_handler(int signum);

int main() 
{
    int pid;

    if ((pid = fork()) < 0) {
        perror("Fork error");
        exit(1);
    }

    if (pid == 0) 
    { // Receiver process
        signal(SIGUSR1, receiver_handler);
        printf("RECEIVER: Waiting for signal from sender...\n");
        while (1) 
        {
            sleep(1);
        }
    } 
    else 
    { // Sender process
        sleep(1);
        printf("SENDER: Sending SIGUSR1 to receiver...\n");
        kill(pid, SIGUSR1);
        sleep(3);

        printf("SENDER: Sending SIGUSR1 to receiver again...\n");
        kill(pid, SIGUSR1);
        sleep(3);

        printf("SENDER: Sending SIGINT to receiver...\n");
        kill(pid, SIGINT);

        wait(NULL); // Wait for receiver to exit
        printf("SENDER: Receiver process has exited.\n");
    }

    return 0;
}

void receiver_handler(int signum) 
{
    if (signum == SIGUSR1) 
    {
        printf("RECEIVER: Received SIGUSR1 from sender.\n");
    } 
    else if (signum == SIGINT) 
    {
        printf("RECEIVER: Received SIGINT from sender. Exiting.\n");
        exit(0);
    }
}












// OUTPUT
// ./Assignment13a5
// RECEIVER: Waiting for signal from sender...
// SENDER: Sending SIGUSR1 to receiver...
// RECEIVER: Received SIGUSR1 from sender.
// SENDER: Sending SIGUSR1 to receiver again...
// RECEIVER: Received SIGUSR1 from sender.
// SENDER: Sending SIGINT to receiver...
// SENDER: Receiver process has exited.
