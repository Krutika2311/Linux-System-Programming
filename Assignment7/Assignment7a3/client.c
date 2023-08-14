// Write a program which is used to create 2 shared libraries and that library should be loaded at run time by the other program.
// First library should contains function to check whether the input number is prime or not.
// Second library should contains function to check whether the input number is perfect or not. 

#include <stdio.h>
#include <dlfcn.h>

int main() 
{
    void* ptr1 = dlopen("/home/krutika/Desktop/LSP_Assignments/Assignment7/Assignment7a3/library1.so", RTLD_LAZY);
    void* ptr2 = dlopen("/home/krutika/Desktop/LSP_Assignments/Assignment7/Assignment7a3/library2.so", RTLD_LAZY);

    if (!ptr1 || !ptr2) {
        printf("Failed to load the libraries.\n");
        return 1;
    }

    int (*is_prime)(int) = dlsym(ptr1, "is_prime");
    int (*is_perfect)(int) = dlsym(ptr2, "is_perfect");

    if (!is_prime || !is_perfect) 
    {
        printf("Failed to get function pointers.\n");
        dlclose(ptr1);
        dlclose(ptr2);
        return 1;
    }

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (is_prime(num)) 
    {
        printf("%d is a prime number.\n", num);
    } 
    else 
    {
        printf("%d is not a prime number.\n", num);
    }

    if (is_perfect(num)) 
    {
        printf("%d is a perfect number.\n", num);
    } 
    else 
    {
        printf("%d is not a perfect number.\n", num);
    }

    dlclose(ptr1);
    dlclose(ptr2);

    return 0;
}


// OUTPUT
// gcc -rdynamic -o Myexe client.c
// ./Myexe

// Enter a number: 28
// 28 is not a prime number.
// 28 is a perfect number.

// Enter a number: 2
// 2 is a prime number.
// 2 is not a perfect number.
