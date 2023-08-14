#include <stdio.h>

int main() 
{
    printf("Process 3 (PID: %d) is running with Parent PID: %d\n", getpid(), getppid());
    printf("Process 3 is done.\n");
    return 0;
}
