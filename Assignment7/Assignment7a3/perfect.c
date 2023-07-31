#include "perfect.h"
#include <stdio.h>

int is_perfect(int num) 
{
    int sum = 0;

    for (int i = 1; i < num; i++) 
    {
        if (num % i == 0) 
        {
            sum += i;
        }
    }

    return (sum == num);
}
