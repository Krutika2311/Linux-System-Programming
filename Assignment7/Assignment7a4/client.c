// main.c
#include <stdio.h>
#include "factorial.h"

int main() {
    int number = 5;
    unsigned long long result = factorial(number);
    printf("Factorial of %d is %llu\n", number, result);
    return 0;
}
