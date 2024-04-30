#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, 0);

    char *data = shmat(shmid, (void *)0, 0);
    printf("Detaching\n");
    shmdt(data);

    return (0);
}