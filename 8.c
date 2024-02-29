#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 

void main()
{
    int file;
    char buf[100];
    file = open("8.txt",O_RDONLY);
    if (file == -1)
	{
		printf("Error opening first_file\n");
		close(file);
		return;
	}
    while(read(file,buf,100))
	{
		printf("%s\n",buf);
	}
}