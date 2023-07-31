//Write a program which accept filename and mode from user and then open that file in specified mode

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(int argc, char *argv[])
{
    int fd = 0;
    int Mode = 0;

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    if(strcmp(argv[2],"Read") == 0)
    {
        Mode = R_OK;
    }
    else if(strcmp(argv[2],"Write") == 0)
    {
        Mode = W_OK;
    }
    else if(strcmp(argv[2],"Execute") == 0)
    {
        Mode = X_OK;
    }

    fd = open(argv[1], Mode);
    if(fd == -1)
    {
        printf("Unable to access %s file in %s mode \n",argv[1],argv[2]);
        return -1;
    }
    else
    {
        printf("You can access %s file in %s mode \n",argv[1],argv[2]);  
    }

    return 0;
}





// OUTPUT 
// ./Assignment1a2 demo.txt Read
// You can access demo.txt file in Read mode 
// ./Assignment1a2 demo.txt Write
// You can access demo.txt file in Write mode 
// ./Assignment1a2 demo.txt Execute
// You can access demo.txt file in Execute mode 
