#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0666); //Make shared memory

    char *data = shmat(shmid, (void *)0, 0); //Map it to current process / Physical memory....

    printf("Enter text to write in shared memory: ");
    scanf("%[^\n]s", data);

    printf("Write successful\n");
    return(0);
}