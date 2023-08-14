// Write a program which performs interprocess communication using the concept of message queue.

// Server
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>

#define  MAX_TEXT 512

struct my_msg_st
{
   long int my_msg_type;
   char some_text[MAX_TEXT];
};

int main()
{
    int running = 1;
    struct my_msg_st some_data;
    int msgid;
    char buffer[BUFSIZ];

    printf("IPC using Message Queue\n");

    msgid = msgget( (key_t)1234,0666 | IPC_CREAT);

    if (msgid == -1)
    {
        fprintf(stderr, "failed to create:\n");
        exit(EXIT_FAILURE);
    }
    printf("Message Queue is Created Successfully \n");

    while(running)
    {
        printf("Enter Some Text: ");
        fgets(buffer, BUFSIZ, stdin);
        some_data.my_msg_type = 1;
        strcpy(some_data.some_text, buffer);

        if(msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1)
        {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
        if(strncmp(buffer, "end", 3) == 0)
        {
            running = 0;
        }
    }

    printf("Terminating the server process\n");

    exit(EXIT_SUCCESS);
}














// OUTPUT
// ./Server
// IPC using Message Queue
// Message Queue is Created Successfully 
// Enter Some Text: Hi
// Enter Some Text: hello
// Enter Some Text: welcome
// Enter Some Text: world
