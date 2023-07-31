#include<stdio.h>
#include "sharedfile.h"

int addition(int a, int b) 
{
    return a + b;
}

int subtraction(int a, int b) 
{
    return a - b;
}

int multiplication(int a, int b) 
{
    return a * b;
}

int division(int a, int b) 
{
    if (b != 0) 
    {
        return a / b;
    } 
    else 
    {
        return 0; // Error: Division by zero.
    }
}
