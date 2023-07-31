// Write a program which accept filename from user and print all information about that file.

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    stat(argv[1],&sobj);

    printf("File name : %s\n",argv[1]);
    printf("File size is : %d\n",sobj.st_size);
    printf("Number of links : %d\n",sobj.st_nlink);
    printf("Inode number : %d\n",sobj.st_ino);
    printf("File system number : %d\n",sobj.st_dev);
    printf("Number of blocks : %d\n",sobj.st_blocks);

    return 0;
}






// OUTPUT 
// ./Assignment1a4 demo.txt

// File name : demo.txt
// File size is : 45
// Number of links : 1
// Inode number : 4468776
// File system number : 2056
// Number of blocks : 8
