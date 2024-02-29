#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
    struct stat info; //stat object which contain all file details..

    char file_name[50];
    printf("Enter a filename\n");
    scanf("%s",file_name);
    stat(file_name,&info); //link file to object.. using stat system call

    printf("inode number=%ld\n",info.st_ino);
    printf("No of Hardlink = %ld\n",info.st_nlink);
    printf("UID = %d\n",info.st_uid);
    printf("GID = %d\n",info.st_gid);
    printf("size = %ld\n",info.st_size);
    printf("Block size = %ld\n",info.st_blksize);
    printf("No. of Blocks = %ld\n",info.st_blocks);
    printf("last file access = %s\n",ctime(&info.st_atime));
    printf("last change = %s\n",ctime(&info.st_ctime));
    printf("last modification = %s\n",ctime(&info.st_mtime));

    return 0;
}