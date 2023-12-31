// Write a program which creates such a process which accept signals from the terminal.

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
  if (signo == SIGINT)
    printf("received SIGINT\n");

  printf("Received signal is %d\n",signo);
}

int main()
{
	printf("Able to receive the signal\n");
  signal(SIGINT, sig_handler);

  while(1) 
	    sleep(1);
  return 0;
}





// OUTPUT
// ./Assignment13a3
// Able to receive the signal
// ^Creceived SIGINT