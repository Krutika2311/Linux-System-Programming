// Write a program which accept directory name from user and copy first 10bytes from all regular files into newly created file named as Demo.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>

#define BLOCKSIZE 10

int main() {
    char dirname[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[20];
    struct stat sobj;
    int fd_demo = 0;
    int fd_file = 0;
    char buffer[BLOCKSIZE];
    ssize_t bytesRead = 0;
    ssize_t bytesWritten = 0;
    off_t offset = 0;

    printf("Enter the name of the directory: ");
    scanf("%s", dirname);

    dp = opendir(dirname);
    if (dp == NULL) {
        printf("Unable to open the directory.\n");
        return -1;
    }

    fd_demo = creat("Demo.txt", 0777);
    if (fd_demo == -1) {
        printf("Unable to create Demo.txt\n");
        closedir(dp);
        return -1;
    }

    while ((entry = readdir(dp)) != NULL) {
        snprintf(name, sizeof(name), "%s/%s", dirname, entry->d_name);
        if (stat(name, &sobj) == 0 && S_ISREG(sobj.st_mode)) {
            fd_file = open(name, O_RDONLY);
            if (fd_file != -1) {
                bytesRead = read(fd_file, buffer, BLOCKSIZE);
                if (bytesRead > 0) {
                    offset = 0;
                    while (offset < bytesRead) {
                        bytesWritten = write(fd_demo, buffer + offset, bytesRead - offset);
                        if (bytesWritten == -1) {
                            printf("Error writing to Demo.txt\n");
                            close(fd_demo);
                            close(fd_file);
                            closedir(dp);
                            return -1;
                        }
                        offset += bytesWritten;
                    }
                }
                close(fd_file);
            }
        }
    }

    close(fd_demo);
    closedir(dp);

    printf("First %d bytes from all regular files copied to Demo.txt successfully.\n", BLOCKSIZE);

    return 0;
}
