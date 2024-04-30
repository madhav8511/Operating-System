
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int msqid = msgget(key, IPC_CREAT | 0666);
    
    struct msqid_ds msg;
    msgctl(msqid, IPC_STAT, &msg);

    printf("Access Permissions - %o\n", msg.msg_perm.mode);
    printf("Uid and gid of owner - %d %d\n", msg.msg_perm.uid, msg.msg_perm.gid);
    printf("Uid and gid of creator - %d %d\n", msg.msg_perm.cuid, msg.msg_perm.cgid);
    printf("Time of last message sent and received in queue - %ld %ld\n", msg.msg_stime, msg.msg_rtime);
    printf("Time of last change - %ld\n", msg.msg_ctime);
    printf("Size of the queue - %ld\n", msg.__msg_cbytes);
    printf("No of messages in queue - %ld\n", msg.msg_qnum);
    printf("Max no. of bytes allowed in queue - %ld\n", msg.msg_qbytes);
    printf("Pid of the last msgsnd and msgrcv - %d %d\n", msg.msg_lspid, msg.msg_lrpid);

    return (0);
}