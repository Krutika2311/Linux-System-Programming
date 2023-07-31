// Write a program which is used to demonstrate concept of I/O redirection.

#include <stdio.h>

int main(int argc, char *argv[]) {
    int iNo1 = 2;
    int iNo2 = 1;
    int iAns = 0;

    for (iNo2 = 0; iNo2 <= 10; iNo2++) {
        iAns = iNo1 * iNo2;
        printf("%d x %d = %d\n", iNo1, iNo2, iAns);
    }

    return 0;
}


// ./Assignment4a1 > output.txt < imput.txt