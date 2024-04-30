#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, 0);

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        printf("Delete unsuccessful\n");
    }
    else
    {
        printf("Delete successful\n");
    }

    return (0);
}