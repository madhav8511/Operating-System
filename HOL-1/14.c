#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <linux/stat.h>

int main() {
    struct stat sb; //Object sb of class stat which contain file details type....

    char name[20];
    printf("Enter file name...\n");
    scanf("%s",name);

    stat(name, &sb); //Link file to object sb...

    printf("File type: ");

    if (S_ISREG(sb.st_mode)){
        printf("Regular file\n");
    }
    else if (S_ISDIR(sb.st_mode)){
        printf("Directory\n");
    }
    else if (S_ISCHR(sb.st_mode)){
        printf("Character Device File\n");
    }
    else if (S_ISBLK(sb.st_mode)){
        printf("Block device file\n");
    }
    else if (S_ISFIFO(sb.st_mode)){
        printf("FIFO file\n");
    }
    else if (S_ISLNK(sb.st_mode)){
        printf("Softlink file\n");
    }
    else if (S_ISSOCK(sb.st_mode)){
        printf("Socket file\n");
    }
    else{
        printf("Unknown? or NO such file exist...\n");
    }
    
    return(0);
}