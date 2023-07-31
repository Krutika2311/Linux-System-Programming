// Write a program which accept filename and on mode and that program check whether our process can access that file in accepted mode or not.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
    if (argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    const char* Fname = argv[1];
    int Mode = 0;

    if (strcmp(argv[2], "Read") == 0)
    {
        Mode = O_RDONLY;
    }
    else if (strcmp(argv[2], "Write") == 0)
    {
        Mode = O_WRONLY;
    }
    else
    {
        printf("Invalid mode argument.\n");
        return -1;
    }

    if (access(Fname, Mode) == 0) {
        printf("Process can access the file '%s' in '%d' mode.\n", Fname, Mode);
    }
    else {
        printf("Process cannot access the file '%s' in '%d' mode.\n", Fname, Mode);
    }

    return 0;
}





// OUTPUT 
// ./Assignment1a3 demo.txt Read
// Process can access the file 'demo.txt' in '0' mode.
// ./Assignment1a3 demo.txt Write
// Process cannot access the file 'demo.txt' in '1' mode.
