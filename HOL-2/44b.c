#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct recv_my_message
{
    long msg_type;
    char msg_text[80];
};

int main()
{
    key_t key = ftok(".",'a');
    struct recv_my_message recv_msg;
    int msqid = msgget(key, IPC_CREAT | 0666);

    int choice;
    printf("Enter 1. for flag type or 2. for IPC\n");
    scanf("%d",&choice);

    if(choice == 1)
    {
        if (msgrcv(msqid, &recv_msg, sizeof(recv_msg), 10, 0) == -1)
        {
            printf("No message\n");
        }
        else
        {
            printf("Message - %s \n", recv_msg.msg_text);
        }
    }
    else if(choice == 2)
    {
        if (msgrcv(msqid, &recv_msg, sizeof(recv_msg), 10, IPC_NOWAIT) == -1)
        {
            printf("No message\n");
        }
        else
        {
            printf("Message - %s \n", recv_msg.msg_text);
        }
    }

    return (0);
}