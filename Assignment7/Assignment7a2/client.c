// Program which is used to create shared library and that library should be loaded at run time by the other program.
// That Library should contains function which accepts 2 file names from user and it will compare the contents of that file.

#include <stdio.h>
#include <dlfcn.h>
#include<stdlib.h>

int main() 
{
    void* ptr = dlopen("/home/krutika/Desktop/LSP_Assignments/Assignment7/Assignment7a2/library.so", RTLD_LAZY);
     if (!ptr) 
     {
        printf("Unable to load library\n");
        return 1;
    }

    int (*compare)(const char*, const char*) = dlsym(ptr, "compareFiles");

    if (!compare) 
    {
        printf("Unable to load library\n");
        dlclose(ptr);
        return 1;
    }

    const char* file1 = "file1.txt";
    const char* file2 = "file2.txt";

    int result = compare(file1, file2);

    if (result == -1) 
    {
        printf("Unable to open one or both files.\n");
    } else if (result == 0) 
    {
        printf("Files are different.\n");
    } else 
    {
        printf("Files are identical.\n");
    }

    dlclose(ptr);
    return 0;
}


// OUTPUT
// gcc -rdynamic -o Myexe client.c
// ./Myexe

// Files are different.