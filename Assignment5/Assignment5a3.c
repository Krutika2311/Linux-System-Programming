// Write a program which accept directory name from user and write information of all regular file in and then read the contents from that file.
// ----------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

struct FileInfo {
    char FileName[256];
    off_t FileSize;
};

int main() {
    char dirname[256];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    struct FileInfo fileInfo;

    printf("Enter the name of the directory: ");
    scanf("%255s", dirname);

    dp = opendir(dirname);
    if (dp == NULL) {
        printf("Unable to open the directory.\n");
        return -1;
    }

    int file = open("file_info.bin", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (file == -1) {
        printf("Failed to create the file.\n");
        closedir(dp);
        return -1;
    }

    while ((entry = readdir(dp)) != NULL) {
        snprintf(fileInfo.FileName, sizeof(fileInfo.FileName), "%s/%s", dirname, entry->d_name);
        if (stat(fileInfo.FileName, &sobj) == 0 && S_ISREG(sobj.st_mode)) {
            fileInfo.FileSize = sobj.st_size;
            write(file, &fileInfo, sizeof(fileInfo));
        }
    }

    close(file);
    closedir(dp);

    int readFile = open("file_info.bin", O_RDONLY);
    if (readFile == -1) {
        printf("Failed to open the file for reading.\n");
        return -1;
    }

    printf("Contents of file_info.bin:\n");
    while (read(readFile, &fileInfo, sizeof(fileInfo)) == sizeof(fileInfo)) {
        printf("File: %s, Size: %ld bytes\n", fileInfo.FileName, fileInfo.FileSize);
    }

    close(readFile);

    return 0;
}
