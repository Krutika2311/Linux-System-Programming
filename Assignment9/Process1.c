// Assignment9a2.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() 
{
    char Buffer[512];
    char count[50];
    int iCnt = 0, iRet = 0, i = 0, fd = 0;

    fd = open("demo.txt", O_RDONLY);
    while ((iRet = read(fd, Buffer, sizeof(Buffer))) != 0) 
    {
        for (i = 0; i < iRet; i++) {
            if ((Buffer[i] >= 'A') && (Buffer[i] <= 'Z')) 
            {
                iCnt++;
            }
        }
    }
    printf("Count Succesfully written in count.txt file.\n");
    close(fd);

    fd = open("count.txt", O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) 
    {
        printf("Unable to open the file count.txt\n");
        return 1;
    }

    int countSize = sprintf(count, "Number of capital characters in demo.txt are: %d\n", iCnt);
    write(fd, count, countSize);

    close(fd);

    return 0;
}
