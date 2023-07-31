// Write a program which accept filename from user and open that file.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char Fname[20];
    int fd = 0;

    printf("Enter the file name that you want to open : \n");
    scanf("%s",Fname);

    fd = open(Fname, O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the File\n");
        return -1;
    }

    else{

        printf("File Successfully opened with fd %d\n",fd);
        close(fd);

    }

    return 0;
}


// OUTPUT
// ./Assignment1a1
// Enter the file name that you want to open : 
// demo.txt
// File Successfully opened with fd 3
