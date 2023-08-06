#include <stdio.h>

int main() 
{
    printf("Process 2 (PID: %d) is running with Parent PID: %d\n", getpid(), getppid());
    printf("Process 2 is done.\n");
    return 0;
}
