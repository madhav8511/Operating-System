#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);

    struct msqid_ds s;
    struct msqid_ds r;

    msgctl(msqid, IPC_STAT, &r);
    printf("Current access Permissions - %o\n", r.msg_perm.mode);

    s.msg_perm.mode = 0777;
    msgctl(msqid, IPC_SET, &s);
    msgctl(msqid, IPC_STAT, &r);
    printf("New access Permissions - %o\n", r.msg_perm.mode);
    return (0);
}