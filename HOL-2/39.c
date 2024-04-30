#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/select.h>
#include<sys/time.h>

int main(){
	fd_set rd;
	struct timeval tv;

	int fd = open("myfifo5", O_RDWR);
	FD_ZERO(&rd);
	FD_SET(fd,&rd);

	tv.tv_sec=10;
	tv.tv_usec=0;

	int i = select(fd+1,&rd,NULL,NULL,&tv);
	if(!i){
		printf("Data not available within 10 seconds\n");
	}
	else{
	
		char read_buf[80];
		read(fd,read_buf,sizeof(read_buf));

		printf("Data from FIFO: %s\n",read_buf);
	}
	return 0;
}