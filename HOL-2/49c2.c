#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

// Define the sembuf struct for semop()
struct sembuf sops;

int main()
{
    // Generate unique keys for shared memory and semaphores
    // Current directory and different id to differentiate
    int shm_key1 = ftok(".", 'C');
    int shm_key2 = ftok(".", 'D');

    int sem_key = ftok(".", 'E');

    // Create 2 shared memory segment - since we need two resoueces
    int shm_id1 = shmget(shm_key1, 1024, 0);
    int shm_id2 = shmget(shm_key2, 1024, 0);

    if (shm_id1 == -1 || shm_id2 == -1)
    {
        printf("Error in shmget call\n");
        return -1;
    }

    // Attach the shared memory segment to process address space
    int *data1 = shmat(shm_id1, NULL, 0);
    int *data2 = shmat(shm_id2, NULL, 0);
    if (data1 == (void *)-1 || data2 == (void *)-1)
    {
        // Error while attaching
        printf("Error in shmat call\n");
        return -1;
    }

    int sem_id = semget(sem_key, 1, 0);
    if (sem_id == -1)
    {
        printf("Error in semget system call\n");
        return -1;
    }

    // Use the semaphores to protect the shared memory
    sops.sem_flg = SEM_UNDO;

    // Critical section
    printf("Before critical section : counter 1 = %d, counter 2 = %d\n", *data1, *data2);

    // LOCKING TWICE - COUNTING SEMAPHORE ACCESS TO 2 Resouces
    sops.sem_num = 0;
    sops.sem_op = -1;
    if (semop(sem_id, &sops, 1) == -1)
    {
        printf("Error in semop system call\n");
        return -1;
    }

    int temp = *data1;
    temp++;
    *data1 = temp;

    printf("During critical section after 1 operation: counter 1 = %d, counter 2 = %d\n", *data1, *data2);

    sops.sem_num = 0;
    sops.sem_op = -1;
    if (semop(sem_id, &sops, 1) == -1)
    {
        printf("Error in semop system call\n");
        return -1;
    }

    temp = *data2;
    temp++;
    *data2 = temp;

    printf("During critical section after 2 operation: counter 1 = %d, counter 2 = %d\n", *data1, *data2);

    printf("Enterto unlock the lock\n");
    getchar();

    // UNLOCK TWICE
    sops.sem_op = 1;
    if (semop(sem_id, &sops, 1) == -1)
    {
        printf("Error in semop system call\n");
        return -1;
    }

    sops.sem_op = 1;
    if (semop(sem_id, &sops, 1) == -1)
    {
        printf("Error in semop system call\n");
        return -1;
    }

    // Detach the shared memory segments from process address space
    if (shmdt(data1) == -1 || shmdt(data2) == -1)
    {
        printf("Error in shmdt call\n");
        return -1;
    }

    return 0;
}