#include "sharedfile.h"
#include <stdio.h>

int compare(const char* filename1, const char* filename2) 
{
    FILE* file1 = fopen(filename1, "r");
    FILE* file2 = fopen(filename2, "r");

    if (!file1 || !file2) 
    {
        // File opening failed
        return -1;
    }

    int ch1, ch2;
    do 
    {
        ch1 = fgetc(file1);
        ch2 = fgetc(file2);

        if (ch1 != ch2) {
            // Files are different
            fclose(file1);
            fclose(file2);
            return 0;
        }
    } 
    while (ch1 != EOF && ch2 != EOF);

    fclose(file1);
    fclose(file2);
    return 1;
}
