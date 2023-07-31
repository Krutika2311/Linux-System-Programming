// Write a program which accept file name which contains data of all file. We have to print all file names whose size is greater than 10 bytes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

struct FileInfo {
    char FileName[20];
    long long int FileSize;
};

int main() {
    char inputFileName[20];

    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    int fd = open(inputFileName, O_RDONLY);
    if (fd == -1) {
        printf("Failed to open the input file.\n");
        return -1;
    }

    char buffer[20];
    struct FileInfo fileInfo;

    printf("File names and sizes greater than 10 bytes:\n");

    while (read(fd, buffer, sizeof(buffer)) > 0) {
        sscanf(buffer, "%s %lld", fileInfo.FileName, &fileInfo.FileSize);
        if (fileInfo.FileSize > 10) {
            printf("%s - %lld bytes\n", fileInfo.FileName, fileInfo.FileSize);
        }
    }

    close(fd);

    return 0;
}
