// Write a program which is used to print home directory and login user name.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main() 
{
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    if (pw == NULL) 
    {
        printf("Failed to get the home directory.\n");
        return 1;
    }
    char* homeDir = pw->pw_dir;

    pw = getpwuid(uid);
    if (pw == NULL) 
    {
        printf("Failed to get the login user name.\n");
        return 1;
    }
    char* userName = pw->pw_name;

    printf("Home directory: %s\n", homeDir);
    printf("Login user name: %s\n", userName);

    return 0;
}
