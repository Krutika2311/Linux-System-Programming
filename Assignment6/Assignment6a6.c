// Write a program which accept filename from user and create hole in file if size is less than 1kb and if it is greater than 1kb then truncate the remaining data.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define KB 1024

int main() {
    char filename[256];

    printf("Enter the filename: ");
    scanf("%s", filename);

    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        printf("Failed to open the file.\n");
        return -1;
    }

    // Set the file offset to the end of the file to determine the file size
    int fileSize = lseek(fd, 0, SEEK_END);

    if (fileSize < KB) {
        // If file size is less than 1 KB, create a hole by seeking 1 KB from the end of the file
        if (lseek(fd, KB, SEEK_END) == -1) {
            printf("Failed to create a hole in the file.\n");
            close(fd);
            return -1;
        }
    } else {
        // If file size is greater than 1 KB, truncate the file at 1 KB
        if (ftruncate(fd, KB) == -1) {
            printf("Failed to truncate the file.\n");
            close(fd);
            return -1;
        }
    }

    close(fd);
    printf("successfully Done.\n");

    return 0;
}




// stat demo.txt
//   File: demo.txt
//   Size: 1209      	Blocks: 8          IO Block: 4096   regular file
// Device: 808h/2056d	Inode: 4468548     Links: 1
// Access: (0664/-rw-rw-r--)  Uid: ( 1000/ krutika)   Gid: ( 1000/ krutika)
// Access: 2023-07-22 00:32:20.817249302 +0530
// Modify: 2023-07-22 00:32:20.829249188 +0530
// Change: 2023-07-22 00:32:20.833249150 +0530
//  Birth: 2023-07-22 00:32:20.817249302 +0530

// ./Assignment6a6
// Enter the filename: demo.txt
// successfully Done.

// stat demo.txt
//   File: demo.txt
//   Size: 1024      	Blocks: 8          IO Block: 4096   regular file
// Device: 808h/2056d	Inode: 4468548     Links: 1
// Access: (0664/-rw-rw-r--)  Uid: ( 1000/ krutika)   Gid: ( 1000/ krutika)
// Access: 2023-07-22 00:32:20.817249302 +0530
// Modify: 2023-07-22 00:32:51.316973734 +0530
// Change: 2023-07-22 00:32:51.316973734 +0530
//  Birth: 2023-07-22 00:32:20.817249302 +0530
