// Client for named pipe for Assignment13a1

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

#define MAX_BUF 1024

int main()
{
    int fd = 0;
    char *path = "/tmp/mypipe";
    char Buffer[MAX_BUF];

    printf("Client is running and reading data from named pipe...\n");
    
    //  open, read, and display the message from the FIFO
    fd = open(path,O_RDONLY);

    read(fd,Buffer,MAX_BUF);

    printf("Data from pipe is : %s\n",Buffer);

    close(fd);
    
    return 0;
}








// OUTPUT
// ./Client
// Client is running and reading data from named pipe...
// Data from pipe is : Marvellous
