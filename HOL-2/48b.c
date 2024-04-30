#include <stdio.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

union semun {
    int val;             
    struct semid_ds *buf;     
    unsigned short int *array; 
};

int main() {
    union semun arg;
    key_t k = ftok(".", 'a');
    int semid = semget(k, 1, IPC_CREAT | 0666);
    
    arg.val = 5; // Set the semaphore value to 5 (counting semaphore behavior)
    semctl(semid, 0, SETVAL, arg);

    return 0;
}
