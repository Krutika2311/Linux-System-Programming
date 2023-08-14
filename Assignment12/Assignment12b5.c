// Client for Assignment12b2
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

#include<sys/msg.h>

struct my_msg_st
{
	long int my_msg_type;
	char some_text[BUFSIZ];
};

int main()
{
    printf("IPC using Message Queue\n");
    printf("Client process is running\n");

	int running = 1;
	int msgid;
	struct my_msg_st some_data;
	long int msg_to_receive = 0;

	msgid = msgget( (key_t)1234,0666 | IPC_CREAT);
    printf("Fetching messages from message queue\n");

	while (running)
	{
		msgrcv(msgid, (void*)&some_data,BUFSIZ,msg_to_receive,0);

		printf("You Wrote: %s",  some_data.some_text);
		if(strncmp(some_data.some_text, "end", 3)== 0)
		{
			running = 0;
		}
	}
    printf("Terminating the client process\n");

	exit(EXIT_SUCCESS);
}








// OUTPUT
//  ./Client
// IPC using Message Queue
// Client process is running
// Fetching messages from message queue
// You Wrote: Hi
// You Wrote: hello
// You Wrote: welcome
// You Wrote: world