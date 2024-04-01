#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 

void main()
{
	char buf;
	int fd_one, fd_two;

	fd_one = open("7_1.txt", O_CREAT | O_RDONLY);

	if (fd_one == -1)
	{
		printf("Error opening first_file\n");
		close(fd_one);
		return;
	}

	fd_two = open("7_2.txt", O_CREAT | O_WRONLY);
	
	while(read(fd_one, &buf, 1))
	{
		write(fd_two, &buf, 1);
	}

	printf("Successful copy\n");

	close(fd_one);
	close(fd_two);
}