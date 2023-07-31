// Write a program which accept directory name from user and create new directory of that name.

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    char dirname[20];

    printf("Enter the name of the directory: ");
    scanf("%s", dirname);

    // Create the directory using mkdir function
    if (mkdir(dirname, 0777) == -1) {
        printf("Failed to create the directory.\n");
        return -1;
    }

    printf("Directory '%s' created successfully.\n", dirname);

    return 0;
}
