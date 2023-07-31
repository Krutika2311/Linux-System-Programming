// Program which is used to create shared library and that library should be loaded at run time by the other program.
// That library should contains functions to perform the arithmetic operations like addtion, Subtraction, Division, and multiplicaion

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() 
{
    void* ptr = dlopen("/home/krutika/Desktop/LSP_Assignments/Assignment7/Assignment7a1/library.so", RTLD_LAZY);
    if (!ptr) 
    {
        printf("Unable to load library\n");
        return 1;
    }

    int (*add)(int, int) = dlsym(ptr, "addition");
    int (*subtract)(int, int) = dlsym(ptr, "subtraction");
    int (*multiply)(int, int) = dlsym(ptr, "multiplication");
    int (*divide)(int, int) = dlsym(ptr, "division");

    int a = 10, b = 5;
    printf("Addition: %d\n", add(a, b));
    printf("Subtraction: %d\n", subtract(a, b));
    printf("Multiplication: %d\n", multiply(a, b));
    printf("Division: %d\n", divide(a, b));

    dlclose(ptr);
    return 0;
}


// OUTPUT
// gcc -rdynamic -o Myexe client.c
// ./Myexe

// Addition: 15
// Subtraction: 5
// Multiplication: 50
// Division: 2
