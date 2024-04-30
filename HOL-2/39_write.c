#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

//mkfifo -m 0744 myfifo5

int main(){
	//first create myfifo file then run
	//mkfifo -m 0744 myfifo
	int fd = open("myfifo5", O_WRONLY);
	char write_buf[80];
	printf("Enter text to write: ");
	scanf(" %[^\n]",write_buf);
	write(fd,write_buf,sizeof(write_buf));
	return 0;
}