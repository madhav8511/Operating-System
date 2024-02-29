# include <stdio.h>
# include <fcntl.h>  
#include <unistd.h> 
# include <sys/stat.h>

int main(int argc,char*argv[])
{
    int n=1;
    printf("Enter No. of Ticket's : ");
    scanf("%d", &n);

    struct flock lock;
    lock.l_whence = SEEK_SET; // Set the starting offset for the lock
    lock.l_len = 0; // Lock the entire file
    lock.l_start = 0; // Start locking from the beginning of the file
    lock.l_type = F_WRLCK; // Set a write lock
    lock.l_pid = getpid();

    // Apply the lock to the file
    int fd = open("17.txt", O_WRONLY , 0744);
    fcntl(fd, F_SETLKW, &lock);

    write(fd, &n, sizeof(int));
    printf("Write successsful\n");

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);

    close(fd);
    return 0;
}