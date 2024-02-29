#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void create_fifo()
{
    int n = mknod("fifo", __S_IFIFO, 0);
    if (n == 0)
    {
        printf("FIFO created successfully\n");
    }
    else
    {
        printf("FIFO creation failed\n");
    }
}

void create_hardlink(char *name)
{
    int h = link(name,"hardlnk");
    if(h==0){
        printf("Hardlink created successfully\n");
    }
    else{
        printf("Harlink creation failed\n");
    }
}

void create_softlink(char *name)
{
    int sft = symlink(name,"softlink");
    if(sft==0)
    {
        printf("Successfully created the soft link\n");
    }
    else
    {
        printf("Softlink not created");
    }
}

int main()
{
    printf("Enter 1 for hard-link\n 2 for soft-link\n 3 for fifo\n");
    int k;
    scanf("%d",&k);
    if(k == 1)
    {
        printf("Enter file name...\n");
        char name[20];
        scanf("%s",name);
        create_hardlink(name);
    }
    else if(k==2)
    {
        printf("Enter file name...\n");
        char name[20];
        scanf("%s",name);
        create_softlink(name);
    }
    else if(k==3)
    {
        create_fifo();
    }
}