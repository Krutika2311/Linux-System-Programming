// Write a program which accept file name from user and offset, remove all the data from that offset.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char filename[20];
    int offset;

    printf("Enter the filename: ");
    scanf("%255s", filename);

    printf("Enter the offset from where you want to remove data: ");
    scanf("%d", &offset);

    int fd = open(filename, O_WRONLY);
    if (fd == -1) {
        printf("Failed to open the file.\n");
        return -1;
    }

    // Set the file offset to the specified position
    if (lseek(fd, offset, SEEK_SET) == -1) {
        printf("Failed to set the file offset.\n");
        close(fd);
        return -1;
    }

    // Truncate the file at the specified offset to remove data after that point
    if (ftruncate(fd, offset) == -1) {
        printf("Failed to remove data from the file.\n");
        close(fd);
        return -1;
    }

    close(fd);
    printf("Data removed from offset %d in the file \"%s\".\n", offset, filename);

    return 0;
}
