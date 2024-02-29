#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 

int main()
{
    int file;
    file = open("10.txt",O_RDWR);
    if(file == -1)
    {
        printf("Some error occured\n");
    }
    char data[10];
    scanf("%s",data);
    int x = write(file,data,10);
    lseek(file,10,SEEK_CUR);
    char data_1[10];
    scanf("%s",data_1);
    int y = write(file,data_1,10);
    printf("%ld\n",lseek(file,sizeof(char),SEEK_CUR));
}