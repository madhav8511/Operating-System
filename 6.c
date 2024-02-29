#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include <unistd.h>
#include <fcntl.h>

int main(void){
    char buffer[80];

    int x = read(0,&buffer,80);
    int y = write(1,&buffer,x);
    printf("X : %d & Y : %d\n",x,y);
}