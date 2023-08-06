// Write a program which create hole of size 1kb at the end of file.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char filename[20];
    printf("Enter the filename: ");
    scanf("%s", filename);

    int fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        printf("Failed to open the file.\n");
        return -1;
    }

    if (lseek(fd, 1024, SEEK_CUR) == -1) {
        printf("Failed to create a hole in the file.\n");
        close(fd);
        return -1;
    }

    close(fd);
    printf("Hole of 1 KB created at the end of the file.\n");

    return 0;
}
