#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, 0);

    int result = msgctl(msqid, IPC_RMID, NULL); //Delete the message queue...

    if( result == -1)
        printf("Delete unsuccessful\n");
    else 
        printf("Delete successful\n");
    
    return (0);
}