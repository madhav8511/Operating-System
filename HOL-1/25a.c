#include <stdio.h>
#include <unistd.h>

int main() {
    
    char *arr[] = {"test_25a", (char *)NULL};
    execv(arr[0], arr);

    // If execvp succeeds, the following code won't be executed.
    perror("execvp failed");
    return 1;
}
