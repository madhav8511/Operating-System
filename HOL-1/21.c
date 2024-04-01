#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd = open("21.txt", O_RDWR);
    if(fd == -1){
        printf("First create file with name output.txt\n");
    }
	int res = fork();

	if(res == 0){
		printf("Child....\n");
		write(fd, "Child", 5);
	}
	else{
		printf("Parent....\n");
		write(fd, "Parent", 6);
	}

	return 0;
}