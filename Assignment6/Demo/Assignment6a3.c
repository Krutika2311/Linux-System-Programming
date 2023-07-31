// Write a program which accept directory name and file name from user and create file in that directory.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    char directoryName[20];
    char fileName[20];

    printf("Enter the name of the directory: ");
    scanf("%s", directoryName);

    printf("Enter the name of the file to create: ");
    scanf("%s", fileName);

    if (mkdir(directoryName, 0777) != 0) {
        printf("Failed to create the directory.\n");
        return -1;
    }

    char fullPath[512];
    snprintf(fullPath, sizeof(fullPath), "%s/%s", directoryName, fileName);

    int fd = open(fullPath, O_WRONLY | O_CREAT, 0777);
    if (fd == -1) {
        printf("Failed to create the file.\n");
        return -1;
    }

    close(fd);
    printf("File \"%s\" created in directory \"%s\".\n", fileName, directoryName);

    return 0;
}



// ./Assignment6a3
// Enter the name of the directory: Demo
// Enter the name of the file to create: assignment6.c
// File "assignment6.c" created in directory "Demo".
