#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int message_q_id = msgget(key, IPC_CREAT | 0666);
    printf("Key: %d, ID: %d\n", key, message_q_id);
    return(0);
}