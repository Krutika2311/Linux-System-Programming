// Write a program which creates two process as reader and writer and that process should communicate with each other using FIFO.

// Server for named pipe

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main()
{
    int fd = 0;

    char *path = "/tmp/mypipe";

    printf("Server is running\n");
    
    //create the FIFO (named pipe) 
    fd = mkfifo(path,0666);
    if(fd == -1)
    {
        printf("Unable to create named pipe\n");
        return -1;
    }

    printf("Server is running and writing the data into named pipe...\n");
    // write data to the FIFO
    fd = open(path,O_WRONLY);

    write(fd,"Marvellous",strlen("Marvellous")+1);

    close(fd);
    
    unlink(path);
    
    printf("Data succesfully written in the pipe\n");
    
    return 0;
}












// OUPUT
// ./Server
// Server is running
// Server is running and writing the data into named pipe...
// Data succesfully written in the pipe
