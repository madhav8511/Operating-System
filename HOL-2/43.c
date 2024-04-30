#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct my_message
{
    long msg_type;
    char msg_text[80];
};

int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);

    struct my_message msg;
    msg.msg_type = 10;
    char text[80];
    printf("Enter message:\n");
    scanf("%[^\n]s", text);

    strcpy(msg.msg_text, text);
    
    if(msgsnd(msqid, (struct msgbuf *)&msg, 80, 0) == -1){
        printf("Message send failed.\n");
    }
    else 
        printf("Message sent successfully.\n");

    return (0);
}