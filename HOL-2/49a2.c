#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct ticket
{
    char *train_name;
    int ticket_num;
};

struct sembuf op; //Locking happen through sembuf structure..

int main()
{

    int fd = open("ticket_record.txt", O_RDWR);

    if (fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    int key = ftok(".", 'a');
    int sem_id = semget(key, 1, 0);

    op.sem_num = 0;
    op.sem_op = -1; //Decrement semaphore value by 1
    op.sem_flg = 0;

    printf("Locking\n");

    int r = semop(sem_id, &op, 1);

    if (r == -1)
    {
        printf("Attempt to aquire semaphore failed!s\n");
        return -1;
    }

    printf("Locked\n");

    struct ticket ticket1;
    read(fd, &ticket1, sizeof(struct ticket));

    printf("Current ticket number: %d\n", ticket1.ticket_num);

    ticket1.ticket_num += 1;
    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket1, sizeof(struct ticket));

    lseek(fd, 0, SEEK_SET); // Checking ticket again to verify incremented number
    read(fd, &ticket1, sizeof(struct ticket));

    printf("Incremented ticket number: %d\n", ticket1.ticket_num);

    printf("Enter to unlock the lock\n");
    getchar();

    op.sem_op = 1; //Increment semaphore value by 1
    r = semop(sem_id, &op, 1); // unlocking

    printf("Semaphore unlocked\n");

    close(fd);
}