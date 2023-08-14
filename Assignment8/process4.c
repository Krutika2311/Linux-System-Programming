#include <stdio.h>
#include <unistd.h>

int main() 
{
    printf("Process 4 (PID: %d) is running with Parent PID: %d\n", getpid(), getppid());
    printf("Process 4 is done.\n");
    return 0;
}
