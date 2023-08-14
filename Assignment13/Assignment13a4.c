// Write a program which accept user defined signal from terminal.

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo) 
{
    printf("Received user-defined signal: %d\n", signo);
}

int main() {
    int user_signal = SIGUSR1;

    printf("Program is waiting for a user-defined signal...\n");

    signal(user_signal, sig_handler);

    while (1) 
    {
        sleep(1);
    }

    return 0;
}






// OUTPUT
// ./Assignment13a4
// Program is waiting for a user-defined signal...
// Received user-defined signal: 10

// kill -SIGUSR1 11491
