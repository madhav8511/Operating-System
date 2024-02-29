#include <stdio.h>
#include <fcntl.h>  
#include <unistd.h> 
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int fd;
    fd = open("17.txt", O_RDWR);

    // Initialize a file lock structure
    struct flock lock;
    lock.l_whence = SEEK_SET; // Set the starting offset for the lock
    lock.l_len = 0; // Lock the entire file
    lock.l_start = 0; // Start locking from the beginning of the file
    lock.l_type = F_WRLCK; // Set a write lock
    lock.l_pid = getpid();

    // Apply the lock to the file
    fcntl(fd, F_SETLKW, &lock);
    printf("File Locked\n");
    int num;
    // Read from file
    lseek(fd, 0, SEEK_SET);
    read(fd, &num, sizeof(int));

    // Display the current number of tickets
    printf("Number of tickets: %d\n", num);
    printf("Incrementing ticket value by 1\n");
    num += 1; // Increment the number of tickets

    // Write the updated number of tickets back to the file
    lseek(fd, 0, SEEK_SET);
    write(fd, &num, sizeof(int));

    // char ch;
    // // Wait for user input to continue
    // read(0, &ch, sizeof(char));
    // Display a message after incrementing and before unlocking
    printf("Incremented. Now unlocking\n");
    printf("Enter to Unlock\n");
    getchar();
    // Unlock the file
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);

    printf("Unlocked\n");

    // Close the file
    close(fd);
}