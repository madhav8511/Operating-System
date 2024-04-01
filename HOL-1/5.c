#include <stdio.h>
#include <fcntl.h>  //provides functions and constants to work with file descriptors
#include <unistd.h> // allows to use creat()

int main()
{
	int x1=creat("5_1.txt",0777); // grants full read, write, and execute permissions
	int x2=creat("5_2.txt",0777);
	int x3=creat("5_3.txt",0777);
	int x4=creat("5_4.txt",0777);
	int x5=creat("5_5.txt",0777);
	printf("fd 1 : %d\n",x1);
	printf("fd 2 : %d\n",x2);
	printf("fd 3 : %d\n",x3);
	printf("fd 4 : %d\n",x4);
	printf("fd 5 : %d\n",x5);
	while(1) // infinte loop
	{};
	return 0;
}





