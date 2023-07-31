// Write a program which accept filename from user and write string in that file.

#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[256];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return -1;
    }

    char string[256];
    printf("Enter the string to write: ");
    scanf(" %[^\n]", string);

    fprintf(file, "%s", string);
    fclose(file);

    printf("String written to the file successfully.\n");

    return 0;
}


// OUTPUT
// ./Assignment2a2
// Enter the filename: demo.txt
// Enter the string to write: Linux System Programming 
// String written to the file successfully.

// cat demo.txt
// Linux System Programming