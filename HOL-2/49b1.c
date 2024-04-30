#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

int main()
{
    int shm_key = ftok(".", 'S');
    int sem_key = ftok(".", 'T');

    int shm_id = shmget(shm_key, 1024, IPC_CREAT | 0666);
    int sem_id = semget(sem_key, 1, IPC_CREAT | 0666);

    // Set the semaphore value to 1 - Binary semaphore
    union semun sem_args;
    sem_args.val = 1;

    if (semctl(sem_id, 0, SETVAL, sem_args) == -1)
    {
        printf("Error in semctl system call\n");
        return -1;
    }

    int *data = shmat(shm_id, (void *)0, 0);
    *data = 100;
    printf("Semaphore created successfully and value assign is : 100\n");
}