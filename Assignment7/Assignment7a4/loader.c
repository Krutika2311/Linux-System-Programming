// loader.c
#include <stdio.h>
#include <dlfcn.h>
#include "factorial.h"

unsigned long long factorial(int n) {
    void* ptr = dlopen("/home/krutika/Desktop/LSP_Assignments/Assignment7/Assignment7a4/factorial.so", RTLD_LAZY);
    if (!ptr) {
         printf("Failed to load the libraries.\n");
        return 1;
    }

    typedef unsigned long long (*factorial_func)(int);
    factorial_func fact = (factorial_func)dlsym(ptr, "factorial");

    if (!fact) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(ptr);
        return 0;
    }

    unsigned long long result = fact(n);
    dlclose(ptr);

    return result;
}
