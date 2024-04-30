// Binary semaphore
#include <stdio.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

union semun
{
    int val;                  
    struct semid_ds *buf;      
    unsigned short int *array; 
};

// Creating binary semaphore and initializing value to the semaphore.
int main()
{
    union semun arg;
    key_t k = ftok(".", 'a');
    int semid = semget(k, 1, IPC_CREAT | 0666);


    arg.val = 1; // Creating a binary semaphore...

    semctl(semid, 0, SETVAL, arg);
    
    return (0);
}