// Write a program which accept directory name from user and print all filenames and its types from that directory.

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    char DirName[256];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;

    printf("Enter the name of the directory: ");
    scanf("%s", DirName);

    dp = opendir(DirName);
    if (dp == NULL) {
        printf("Unable to open directory\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL) {
        char path[512];
        snprintf(path, sizeof(path), "%s/%s", DirName, entry->d_name);

        if (stat(path, &sobj) == 0) {
            if (S_ISREG(sobj.st_mode)) {
                printf("%s: Regular file\n", entry->d_name);
            } else if (S_ISDIR(sobj.st_mode)) {
                printf("%s: Directory\n", entry->d_name);
            } else if (S_ISLNK(sobj.st_mode)) {
                printf("%s: Symbolic link\n", entry->d_name);
            } else {
                printf("%s: Other\n", entry->d_name);
            }
        } else {
            printf("%s: Failed to retrieve information\n", entry->d_name);
        }
    }

    closedir(dp);
    return 0;
}


// OUTPUT

// ./Assignment2a4
// Enter the name of the directory: Demo
// FileSystem13: Regular file
// ..: Directory
// FileSystem22.c: Regular file
// Demo1: Directory
// FileSystem12.c: Regular file
// FileSystem22: Regular file
// FileSystem21.c: Regular file
// .: Directory
