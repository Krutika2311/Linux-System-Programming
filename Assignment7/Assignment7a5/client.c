// Write a program which creates static library which contains filename from user and which displays the information of that file.

#include <stdio.h>
#include "sharedfile.h"

int main() 
{
    char filename[256];
    printf("Enter the filename: ");
    scanf("%255s", filename);

    if (display_file_info(filename) == 0) 
    {
        printf("File information displayed successfully.\n");
    } else 
    {
        printf("Failed to display file information.\n");
    }

    return 0;
}



// gcc -static client.c -o Myexe sharedfile.a
// ./Myexe

// Enter the filename: client.c
// File name : client.c
// File size is : 368 bytes
// Number of links : 1
// Inode number : 4469479
// File system number : 2056
// Number of blocks : 8
// File information displayed successfully.
