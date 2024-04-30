#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

struct sembuf sops;

int main()
{
    // Generate unique keys for shared memory and semaphore
    // Current directory and different id to differentiate
    int shm_key = ftok(".", 'S');
    int sem_key = ftok(".", 'T');

    // Create the shared memory segment of size 1024
    int shm_id = shmget(shm_key, 1024, 0);

    // Attach the shared memory segment to process address space
    int *data = shmat(shm_id, (void *)0, 0);

    int sem_id = semget(sem_key, 1, 0);
    if (sem_id == -1)
    {
        printf("Error in semget system call\n");
        return -1;
    }

    // Use the semaphore to protect the shared memory
    sops.sem_num = 0;
    sops.sem_op = -1;
    sops.sem_flg = 0;

    printf("Before critical section: counter = %d\n", *data);

    if (semop(sem_id, &sops, 1) == -1)
    {
        printf("Error in semop system call\n");
        return -1;
    }

    // This is the critical section
    int temp = *data;
    temp++;
    *data = temp;
    // CHANGING SHARED MEMORY SEGMENT

    printf("After critical section: counter = %d\n", *data);

    printf("Enter to unlock the lock\n");
    getchar();

    // Release the semaphore
    sops.sem_op = 1;
    if (semop(sem_id, &sops, 1) == -1)
    {
        printf("Error in semop system call\n");
        return -1;
    }

    // Detach the shared memory segment
    if (shmdt(data) == -1)
    {
        printf("Error in shmdt system call\n");
        return -1;
    }

    return 0;
}