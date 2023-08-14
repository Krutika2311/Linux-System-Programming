// Write a program which map any file in memory and read that data from that mapped file.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    const char *filename = "demo.txt";
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        printf("Failed to open the file for reading.\n");
        return -1;
    }

    // Get the size of the file
    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1) {
        printf("Failed to get file information.\n");
        close(fd);
        return -1;
    }
    size_t file_size = file_stat.st_size;

    // Map the file into memory
    void *mapped_memory = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapped_memory == MAP_FAILED) {
        printf("Failed to map the file into memory.\n");
        close(fd);
        return -1;
    }

    close(fd);

    printf("Data from the mapped file:\n%s\n", (char *)mapped_memory);

    // Unmap the memory
    if (munmap(mapped_memory, file_size) == -1) {
        printf("Failed to unmap memory.\n");
    }

    return 0;
}









// OUTPUT
// ./Assignment12a4
// Data from the mapped file:
// ABCDEFGHIjklmnop