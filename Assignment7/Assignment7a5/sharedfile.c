#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "sharedfile.h"

int display_file_info(const char* filename) 
{
    struct stat sobj;

    if (stat(filename, &sobj) < 0) 
    {
        perror("Error getting file information");
        return -1;
    }

    printf("File name : %s\n", filename);
    printf("File size is : %lld bytes\n", (long long)sobj.st_size);
    printf("Number of links : %ld\n", (long)sobj.st_nlink);
    printf("Inode number : %ld\n", (long)sobj.st_ino);
    printf("File system number : %ld\n", (long)sobj.st_dev);
    printf("Number of blocks : %lld\n", (long long)sobj.st_blocks);

    return 0;
}
