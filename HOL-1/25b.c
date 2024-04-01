/*
Name-Siddhesh Deshpande
Roll no-IMT2022080
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    char *arr[] = {"test_25b", "hello", (char *)NULL};
    execv(arr[0], arr);
    return 0;
}