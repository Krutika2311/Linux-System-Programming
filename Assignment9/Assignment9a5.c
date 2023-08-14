// Write a program which is used to yield our processor by using appropriate system call.

#include <stdio.h>
#include <sched.h> // Include for sched_yield()

int main() {
    printf("Starting the program...\n");

    for (int i = 1; i <= 5; i++) {
        printf("Yield %d: Processor yielded successfully.\n", i);
        sched_yield(); 
    }

    printf("Program completed.\n");
    return 0;
}

// ./Assignment9a5
// Starting the program...
// Yield 1: Processor yielded successfully.
// Yield 2: Processor yielded successfully.
// Yield 3: Processor yielded successfully.
// Yield 4: Processor yielded successfully.
// Yield 5: Processor yielded successfully.
// Program completed.
