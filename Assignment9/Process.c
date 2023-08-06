#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

int main()
{
    DIR *dir = opendir("/home/krutika/Desktop/");
    if (dir == NULL)
    {
        printf("Failed to open the desktop directory.\n");
        return 1;
    }

    int fd = open("Demo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        printf("Failed to create the Demo.txt file.\n");
        closedir(dir);
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        char buffer[1024];
        sprintf(buffer, "%s\n", entry->d_name);

        // Write the file name to the Demo.txt file
        write(fd, buffer, strlen(buffer));
    }

    close(fd);
    closedir(dir);
    printf("File names on the desktop written to Demo.txt by the process.\n");

    return 0;
}
