// Write a program which accept directory name from user and delete all such files whose size is greater than 100 bytes.

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    char directoryName[20];

    printf("Enter the name of the directory: ");
    scanf("%s", directoryName);

    DIR *dp = opendir(directoryName);
    if (dp == NULL) {
        printf("Failed to open the directory.\n");
        return -1;
    }

    struct dirent *entry;
    struct stat sobj;
    char filePath[512];

    printf("Files with size greater than 100 bytes in the directory \"%s\":\n", directoryName);

    while ((entry = readdir(dp)) != NULL) {
        sprintf(filePath, "%s/%s", directoryName, entry->d_name);
        if (stat(filePath, &sobj) == 0 && S_ISREG(sobj.st_mode) && sobj.st_size > 100) {
            printf("%s\n", entry->d_name);
            if (unlink(filePath) == -1) {
                printf("Failed to delete the file: %s\n", entry->d_name);
            } else {
                printf("File deleted: %s\n", entry->d_name);
            }
        }
    }

    closedir(dp);

    return 0;
}


// ./Assignment6a4

// Enter the name of the directory: Demo
// Files with size greater than 100 bytes in the directory "Demo":
// Assignment6a3.c
// File deleted: Assignment6a3.c
// Assignment6a6.c
// File deleted: Assignment6a6.c
// Assignment6a4
// File deleted: Assignment6a4
// Assignment6a3
// File deleted: Assignment6a3
// Assignment6a5.c
// File deleted: Assignment6a5.c
// Assignment6a2.c
// File deleted: Assignment6a2.c
// Assignment6a2
// File deleted: Assignment6a2
// Assignment6a1
// File deleted: Assignment6a1
// Assignment6a4.c
// File deleted: Assignment6a4.c
// Assignment6a1.c
// File deleted: Assignment6a1.c
